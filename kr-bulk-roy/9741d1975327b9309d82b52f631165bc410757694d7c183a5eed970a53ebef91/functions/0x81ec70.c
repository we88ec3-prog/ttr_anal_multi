
undefined4 FUN_0081ec70(uint param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 unaff_ESI;
  
  if (((param_1 & 0x41) != 0) && (iVar1 = FUN_0081eaa0(in_EAX,param_1), iVar1 == 0)) {
    return 0;
  }
  if (((param_1 & 2) != 0) && (iVar1 = FUN_0081eb80(in_EAX,unaff_ESI,0), iVar1 != 0)) {
    return 0;
  }
  if (((param_1 & 4) != 0) && (iVar1 = FUN_0081eb80(in_EAX + 0x20,unaff_ESI,0), iVar1 != 0)) {
    return 0;
  }
  if (((param_1 & 8) != 0) && (iVar1 = FUN_0081eb80(in_EAX + 0x10,unaff_ESI,1), iVar1 != 0)) {
    return 0;
  }
  if (((param_1 & 0x10) != 0) && (iVar1 = FUN_0081eb80(in_EAX + 0x30,unaff_ESI,0), iVar1 != 0)) {
    return 0;
  }
  return 1;
}

