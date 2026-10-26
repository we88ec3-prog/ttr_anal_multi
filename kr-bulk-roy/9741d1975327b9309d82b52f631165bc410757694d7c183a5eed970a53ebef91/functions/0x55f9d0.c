
void FUN_0055f9d0(void)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  if (*in_EAX != 0) {
    if (in_EAX[0xb] == 1) {
      iVar2 = FUN_0055ed60(0x3d072b02);
      if (iVar2 != 0) {
        in_EAX[0xb] = 2;
        FUN_004054c0();
        FUN_0058aad0(0xf4320);
        FUN_0055f370();
      }
    }
    else if ((in_EAX[0xb] == 2) && (iVar2 = FUN_0055ed60(0x3d072b02), iVar2 != 0)) {
      if (in_EAX[9] != 0) {
        FUN_0056c620();
      }
      in_EAX[0xb] = 0;
    }
    if (((in_EAX[0xb] == 0) && (iVar2 = in_EAX[1], *(int *)(iVar2 + 0x28) != 0)) &&
       (iVar1 = *(int *)(iVar2 + 0x3c), *(int *)(iVar2 + 0x3c) = iVar1 + -1, iVar1 < 1)) {
      *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar2 + 0x38);
      if (*(int *)(iVar2 + 0x34) < *(int *)(iVar2 + 0x10)) {
        *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
      }
      else {
        *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x10);
      }
    }
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[3] = 0;
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[4] = 0xf440b;
      FUN_004072a0();
      return;
    }
    FUN_004072a0();
  }
  return;
}

