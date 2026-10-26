
int FUN_008bb8b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  int iVar1;
  int *unaff_EDI;
  int local_8;
  
  if (in_EAX == (undefined4 *)0x0) {
    return 0x21;
  }
  if (param_1 == 0) {
    return 6;
  }
  *unaff_EDI = 0;
  iVar1 = FUN_008baee0(*in_EAX,0x28,&local_8);
  if (local_8 == 0) {
    FUN_008b9790(iVar1,param_1,param_2);
    *(undefined4 *)(iVar1 + 0x18) = param_3;
    *unaff_EDI = iVar1;
  }
  return local_8;
}

