
/* Library Function - Single Match
    __set_abort_behavior
   
   Library: Visual Studio 2010 Release */

uint __cdecl __set_abort_behavior(uint _Flags,uint _Mask)

{
  uint uVar1;
  
  uVar1 = DAT_00d61f40;
  DAT_00d61f40 = ~_Mask & DAT_00d61f40 | _Flags & _Mask;
  return uVar1;
}

