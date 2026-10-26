
/* Library Function - Single Match
    __Getwctype
   
   Library: Visual Studio 2010 Release */

short __cdecl __Getwctype(wchar_t param_1,_Ctypevec *param_2)

{
  BOOL BVar1;
  ushort local_8 [2];
  
  BVar1 = GetStringTypeW(1,&param_1,1,local_8);
  return -(ushort)(BVar1 != 0) & local_8[0];
}

