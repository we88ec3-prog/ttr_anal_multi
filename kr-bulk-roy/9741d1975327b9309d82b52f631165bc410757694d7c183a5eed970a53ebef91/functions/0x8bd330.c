
int FUN_008bd330(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *in_EAX;
  iVar2 = FUN_008bc310();
  if (iVar2 == 0) {
    iVar2 = FUN_008bcef0();
    if (iVar2 == 0) {
      iVar2 = FUN_008bbac0();
      FUN_008b9f80(uVar1,local_c);
      if (iVar2 == 0) {
        *(undefined4 *)*param_3 = 1;
      }
      return iVar2;
    }
    iVar2 = FUN_008bcef0();
    if (iVar2 == 0) {
      iVar2 = FUN_008bbd40();
      FUN_008b9f80(uVar1,local_c);
      if (iVar2 == 0) {
        *(undefined4 *)*param_3 = local_8;
      }
    }
  }
  return iVar2;
}

