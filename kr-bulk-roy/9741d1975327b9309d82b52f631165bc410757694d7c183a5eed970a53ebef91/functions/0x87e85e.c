
/* Library Function - Single Match
    _ldexpf
   
   Library: Visual Studio 2010 Release */

float10 __cdecl ldexpf(float param_1,int param_2)

{
  double dVar1;
  
  dVar1 = _ldexp((double)param_1,param_2);
  return (float10)(float)dVar1;
}

