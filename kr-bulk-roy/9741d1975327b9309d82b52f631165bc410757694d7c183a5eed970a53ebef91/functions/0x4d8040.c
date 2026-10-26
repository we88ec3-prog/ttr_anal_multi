
undefined4 FUN_004d8040(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_14;
  
  FUN_004f0c70();
  FUN_004f0c70();
  iVar1 = FUN_00542210();
  iVar1 = *(int *)(iVar1 + 8);
  iVar2 = local_20 - local_14;
  iVar3 = FUN_004d8460();
  if ((uint)(local_14 - iVar1) < (uint)(*(int *)(iVar3 + 8) - local_20)) {
    FUN_00542210();
    FUN_004d8340();
    if (iVar2 != 0) {
      iVar1 = *(int *)(in_EAX + 0x10);
      do {
        if (iVar1 != 0) {
          *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + 1;
          if ((uint)(*(int *)(in_EAX + 8) * 2) <= *(uint *)(in_EAX + 0xc)) {
            *(undefined4 *)(in_EAX + 0xc) = 0;
          }
          iVar1 = iVar1 + -1;
          if (iVar1 == 0) {
            *(undefined4 *)(in_EAX + 0xc) = 0;
          }
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(in_EAX + 0x10) = iVar1;
    }
  }
  else {
    FUN_004d8460();
    FUN_004d83d0();
    if (iVar2 != 0) {
      iVar1 = *(int *)(in_EAX + 0x10);
      do {
        if ((iVar1 != 0) && (iVar1 = iVar1 + -1, iVar1 == 0)) {
          *(undefined4 *)(in_EAX + 0xc) = 0;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(in_EAX + 0x10) = iVar1;
    }
  }
  FUN_00542210();
  FUN_0050b4b0();
  return param_1;
}

