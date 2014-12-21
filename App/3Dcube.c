typedef float Vector3[3];
typedef	float Matrix4x4[4][4];
typedef char int8;

void V3_Set(Vector3 v,float x,float y,float z);
void V3_Copy(Vector3 dst, Vector3 src);



void M4X4_Copy(Matrix4x4 dst, Matrix4x4 src);

void M4X4_Identity(Matrix4x4 temporaneo);

void M4X4_Mul(Matrix4x4 res, Matrix4x4 m1, Matrix4x4 m2);

void M4X4_MulSelf(Matrix4x4 m1, Matrix4x4 m2);

void MatrixVectorMul(Vector3 res, Vector3 v, Matrix4x4 temporaneo);

void CreateRotateMat(int8 rx,int8 ry,int8 rz);
void TransformVec(Vector3 res, Vector3 v, Matrix4x4 temporaneo);

void SetFov(float newFov);
void RecalcDists(void);
void Project(Vector3 coords);

void RenderFrame(void);
void InitTrigotable(void);

void CreateBox();
void Oscillate();
void cubeRota(void);



void V3_Set(Vector3 v,float x,float y,float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void V3_Copy(Vector3 dst, Vector3 src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
}

void M4X4_Copy(Matrix4x4 dst, Matrix4x4 src)
{
	unsigned char i,j;

	for(i = 0;i < 4;i++)
		for(j = 0;j < 4;j++)
			dst[i][j] = src[i][j];
}

void M4X4_Identity(Matrix4x4 temporaneo)
{
	temporaneo[0][0] = 1.0;
	temporaneo[0][1] = 0;
	temporaneo[0][2] = 0;
	temporaneo[0][3] = 0;
	temporaneo[1][0] = 0;
	temporaneo[1][1] = 1.0;
	temporaneo[1][2] = 0;
	temporaneo[1][3] = 0;
	temporaneo[2][0] = 0;
	temporaneo[2][1] = 0;
	temporaneo[2][2] = 1.0;
	temporaneo[2][3] = 0;
	temporaneo[3][0] = 0;
	temporaneo[3][1] = 0;
	temporaneo[3][2] = 0;
	temporaneo[3][3] = 1.0;
}

void M4X4_Mul(Matrix4x4 res, Matrix4x4 m1, Matrix4x4 m2)
{
	float	e1,e2,e3,e4;
	unsigned char	i;

	for(i = 0;i < 4;i++)
	{
		e1 = m1[i][0];
		e2 = m1[i][1];
		e3 = m1[i][2];
		e4 = m1[i][3];

		res[i][0] = e1 * m2[0][0] + e2 * m2[1][0] + e3 * m2[2][0] + e4 * m2[3][0];
		res[i][1] = e1 * m2[0][1] + e2 * m2[1][1] + e3 * m2[2][1] + e4 * m2[3][1];
		res[i][2] = e1 * m2[0][2] + e2 * m2[1][2] + e3 * m2[2][2] + e4 * m2[3][2];
		res[i][3] = e1 * m2[0][3] + e2 * m2[1][3] + e3 * m2[2][3] + e4 * m2[3][3];
	}
}

void M4X4_MulSelf(Matrix4x4 m1, Matrix4x4 m2)
{
	float	e1,e2,e3,e4;
	unsigned char	i;

	for(i = 0;i < 4;i++)
	{
		e1 = m1[i][0];
		e2 = m1[i][1];
		e3 = m1[i][2];
		e4 = m1[i][3];

		m1[i][0] = e1 * m2[0][0] + e2 * m2[1][0] + e3 * m2[2][0] + e4 * m2[3][0];
		m1[i][1] = e1 * m2[0][1] + e2 * m2[1][1] + e3 * m2[2][1] + e4 * m2[3][1];
		m1[i][2] = e1 * m2[0][2] + e2 * m2[1][2] + e3 * m2[2][2] + e4 * m2[3][2];
		m1[i][3] = e1 * m2[0][3] + e2 * m2[1][3] + e3 * m2[2][3] + e4 * m2[3][3];
	}
}

void MatrixVectorMul(Vector3 res, Vector3 v, Matrix4x4 temporaneo)
{
	res[0] = v[0] * temporaneo[0][0] + v[1] * temporaneo[1][0] + v[2] * temporaneo[2][0] + temporaneo[3][0];
	res[1] = v[0] * temporaneo[0][1] + v[1] * temporaneo[1][1] + v[2] * temporaneo[2][1] + temporaneo[3][1];
	res[2] = v[0] * temporaneo[0][2] + v[1] * temporaneo[1][2] + v[2] * temporaneo[2][2] + temporaneo[3][2];
}

// clamps the given angle to the range between 0 and 180 degrees
#define CLAMP_ANGLE(x)							\
{												\
	if(x >=180) x = 0;			\
}

#define NUM_POINTS            14
#define HALF_DISPLAY_WIDTH  64.0    // half width of the used display in pixels
#define HALF_DISPLAY_HEIGHT 32.0    // half height of the used display in pixels


// defines whether FPS should be displayed or not
#define SHOW_FPS

// string used for text output
char     str[20];

float		fov,							   // FieldOfView angle
			distX,							// Focal distance to X projection plane
			distY;							// Focal distance to Y projection plane

// rotation angles of the 3D-object
int8		rotX = 0,
			rotY = 0,
			rotZ = 0;

// position of the 3D-object
float    posX = 0,
         posY = 0,
         posZ = 10.0;


Vector3  points[NUM_POINTS];
char     indices[24];

float    _sin[180];  // variables for the precalculated sin &
float    _cos[180];  // cos values


Matrix4x4	temp,matWorld;			// Transformation matrices
float	      scrX,scrY;
Vector3	   coordsWorld;


signed short int counter=0;
signed long int frametime_i;
float fps;

// define the 3D-object
void CreateBox()
{
   // 8 corners of the box
   V3_Set(points[0],-1.0,-1.0,-1.0);
   V3_Set(points[1],1.0,-1.0,-1.0);
   V3_Set(points[2],-1.0, 1.0,-1.0);
   V3_Set(points[3],1.0, 1.0,-1.0);
	V3_Set(points[4],-1.0,-1.0, 1.0);
   V3_Set(points[5], 1.0,-1.0, 1.0);
   V3_Set(points[6],-1.0, 1.0, 1.0);
   V3_Set(points[7],1.0, 1.0, 1.0);

   // coordinates of the oscillating spheres in
   // the center of the box
	V3_Set(points[8],0.0,0.0, 0.35);
   V3_Set(points[9], 0.0,0.0, -0.35);
   V3_Set(points[10],0.0, 0.35, 0.0);
   V3_Set(points[11],0.0, -0.35, 0.0);
   V3_Set(points[12],-0.35, 0.0, 0.0);
   V3_Set(points[13],0.35, 0.0, 0.0);

   // define indices for correct connections between the box-vertices
	indices[0]=0;
   indices[1]=1;
	indices[2]=2;
   indices[3]=3;
	indices[4]=4;
   indices[5]=5;
	indices[6]=6;
   indices[7]=7;
	indices[8]=0;
   indices[9]=4;
	indices[10]=1;
   indices[11]=5;
	indices[12]=2;
   indices[13]=6;
	indices[14]=3;
   indices[15]=7;
	indices[16]=0;
   indices[17]=2;
   indices[18]=1;
   indices[19]=3;
	indices[20]=4;
   indices[21]=6;
	indices[22]=5;
   indices[23]=7;
}



// animate the spheres in the box
void Oscillate()
{
   static int osc=0;
   osc+=2;
   CLAMP_ANGLE(osc);

   V3_Set(points[8],0.0,0.0, 1.5*_sin[osc]);
   V3_Set(points[9], 0.0,0.0, -1.5*_sin[osc]);
   V3_Set(points[10],0.0, 1.5*_sin[osc], 0.0);
   V3_Set(points[11],0.0, -1.5*_sin[osc], 0.0);
   V3_Set(points[12],-1.5*_sin[osc], 0.0, 0.0);
   V3_Set(points[13],1.5*_sin[osc], 0.0, 0.0);
}



// calculate sin/cos-table
void InitTrigotable(void)
{
   int8 i;
   float a;
   for(i=0; i<180; i++)
   {
      a=(float)i*M_PI/90.0;
      _sin[i]=sin(a);
      _cos[i]=cos(a);
   }
}






// calculate a rotation matrix
void CreateRotateMat(int8 rx,int8 ry,int8 rz)
{
   Matrix4x4   mrot;

   // multiply the world-matrix with the rotation matrices
	M4X4_Copy(temp,matWorld);

   M4X4_Identity(mrot);
	mrot[1][1] = _cos[rx];
	mrot[1][2] = _sin[rx];
	mrot[2][1] = -mrot[1][2];
	mrot[2][2] = mrot[1][1];

	M4X4_Mul(matWorld,mrot,temp);

	M4X4_Identity(mrot);
	mrot[0][0] = _cos[ry];
	mrot[0][2] = -_sin[ry];
	mrot[2][0] = -mrot[0][2];
	mrot[2][2] = mrot[0][0];

	M4X4_Mul(temp,mrot,matWorld);

	M4X4_Identity(mrot);
	mrot[0][0] = _cos[rz];
	mrot[0][1] = _sin[rz];
	mrot[1][0] = -mrot[0][1];
	mrot[1][1] = mrot[0][0];

	M4X4_Mul(matWorld,mrot,temp);

}





// Sets a field-of-view angle
void SetFov(float newFov)
{
	fov = newFov;

	// Recalc focal distances
	RecalcDists();
}



// (Re)calculates the distances to the X/Y projection planes
void RecalcDists(void)
{
	float cotFOV;
   cotFOV = cos(fov/2.0) / sin(fov/2.0);

	distX = cotFOV * HALF_DISPLAY_WIDTH;
	distY = cotFOV * HALF_DISPLAY_HEIGHT;
}



// Converts 3D coordinates to 2D screen coords
void Project(Vector3 coords)
{
   float invZ;

	// Skip if z = 0
	if(coords[2] == 0)
		return;

	invZ = 1.0f / coords[2];

	// Calculate the projected values using the formulas
	scrX = coords[0] * distX * invZ + HALF_DISPLAY_WIDTH;
	scrY = -coords[1] * distY * invZ + HALF_DISPLAY_HEIGHT;
}


// render the cube
void RenderFrame(void)
{
	int8 i,t;
	int8	x1,y1,x2,y2;

	// clamp rotation angles to range [0...180] degrees
	CLAMP_ANGLE(rotX);
	CLAMP_ANGLE(rotY);
	CLAMP_ANGLE(rotZ);

   // create translation matrix
	M4X4_Identity(matWorld);
	M4X4_Identity(temp);
	temp[3][0] = posX;
	temp[3][1] = posY;
	temp[3][2] = posZ;
	M4X4_MulSelf(matWorld,temp);

   // create rotation matrix
	CreateRotateMat(rotX,rotY,rotZ);


	// Loop through the lines
	for(i = 0;i <12;i++)
	{
		// Transform and project first point
      t=indices[i*2];
		MatrixVectorMul(coordsWorld,points[t],matWorld);
		Project(coordsWorld);

		x1 = (int8)scrX;
		y1 = (int8)scrY;

		// Transform and project second point
      t=indices[i*2+1];
		MatrixVectorMul(coordsWorld,points[t],matWorld);
		Project(coordsWorld);

		x2 = (int8)scrX;
		y2 = (int8)scrY;


		// Draw the line

		draw_line(x1,y1,x2,y2,WHITE);

	}


   // draw the spheres
	for(i = 0;i <14;i++)
	{
 		MatrixVectorMul(coordsWorld,points[i],matWorld);
		Project(coordsWorld);

		x2 = (int8)scrX;
		y2 = (int8)scrY;

      LCD_Cercle(x2,y2,(int8)(20.0/coordsWorld[2]), 1,WHITE);
   }

}

void cubeRota(void)
{
    DelayMs(100);
   LCD_CLS(BLACK);
   CreateBox();            // create the 3d-object
   InitTrigotable();       // precalc sin/cos-values
   SetFov(45.0);
    while(TRUE)
    {
        RenderFrame();
        rotX++;
      rotY++;
      rotZ++;
      if(PORTDbits.RD14==0) break;

    }
   DelayMs(100);

}