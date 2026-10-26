
void FUN_0074f980(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *unaff_EDI;
  int local_2c;
  int iStack_18;
  int iStack_14;
  
  if (unaff_EDI != (int *)0x0) {
    if ((char)unaff_EDI[0x56] != '\0') {
      (**(code **)(*unaff_EDI + 0x174))(10);
      unaff_EDI[0x2d] = 0;
      unaff_EDI[0x2e] = 0;
      pcVar1 = *(code **)(*unaff_EDI + 0x128);
      unaff_EDI[0x2f] = 0;
      unaff_EDI[0x30] = 0;
      (*pcVar1)();
      FUN_00754510();
    }
    piVar3 = (int *)unaff_EDI[7];
    if (piVar3[2] == 6) {
      iVar4 = unaff_EDI[0x18];
      FUN_00750720(param_1,*(undefined4 *)(param_1 + 0xa8),*(undefined4 *)(param_1 + 0xac));
      unaff_EDI[0x18] = 0;
      if (iStack_14 < 0) {
        iStack_14 = 0;
      }
      if (iStack_18 < 0) {
        iStack_18 = 0;
      }
      FUN_00749a00(iStack_18,iStack_14);
      (**(code **)(*unaff_EDI + 0x94))(1);
      unaff_EDI[0x18] = iVar4;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x13cc);
      unaff_EDI[0x18] = iVar4;
      if ((iVar4 != 0) && (piVar3[2] != 6)) {
        (**(code **)(*piVar3 + 0x30))();
      }
      FUN_00746f70();
      piVar3 = (int *)FUN_00443da0();
      local_2c = *piVar3;
      iVar4 = FUN_00443da0();
      iVar4 = *(int *)(iVar4 + 4);
      iVar2 = *(int *)(param_1 + 0xa0);
      iVar5 = FUN_00443da0();
      if (iVar2 < *(int *)(iVar5 + 8)) {
        piVar3 = (int *)FUN_00443da0();
        local_2c = (iVar2 - piVar3[2]) + *piVar3;
      }
      iVar2 = *(int *)(param_1 + 0xa4);
      iVar5 = FUN_00443da0();
      if (iVar2 < *(int *)(iVar5 + 0xc)) {
        iVar4 = FUN_00443da0();
        iVar4 = (*(int *)(iVar4 + 4) - *(int *)(iVar4 + 0xc)) + iVar2;
      }
      FUN_00749970(local_2c,iVar4);
      unaff_EDI[0x18] = 0;
    }
    (**(code **)(*unaff_EDI + 200))();
    *(int **)(param_1 + 0x13ec) = unaff_EDI;
    return;
  }
  *(undefined4 *)(param_1 + 0x13ec) = 0;
  return;
}

