
void FUN_007d65a0(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_ESI;
  int iVar4;
  int local_c;
  int local_8;
  
  local_8 = unaff_ESI[4];
  iVar1 = *unaff_ESI;
  param_1 = param_1 * 30.0 + (float)unaff_ESI[2];
  unaff_ESI[2] = (int)param_1;
  FUN_0082ef00(&local_8);
  if ((local_c != *(int *)(iVar1 + 0x38)) && (local_8 = *(int *)(local_c + 0x10), local_8 != 0)) {
    iVar1 = *(int *)(local_8 + 0x10);
    param_1 = (float)**(int **)(local_8 + 0xc);
    uVar2 = FUN_008fed10();
    iVar4 = local_8;
    (**(code **)((int)param_1 + 0x1c))(uVar2);
    FUN_00780150(*(int *)(iVar4 + 0xc),*(undefined4 *)(*(int *)(iVar4 + 0xc) + 0x30));
    iVar1 = *(int *)(iVar1 + 0x178);
    param_1 = *(float *)(*(int *)(unaff_ESI[3] + 0x74) + 0x178);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        if ((int)param_1 <= iVar4) break;
        iVar3 = FUN_00843ef0();
        uVar2 = *(undefined4 *)(iVar3 + 0xb8);
        iVar3 = FUN_00843ef0();
        iVar4 = iVar4 + 1;
        *(undefined4 *)(iVar3 + 0xb8) = uVar2;
      } while (iVar4 < iVar1);
    }
    if ((((float)unaff_ESI[1] < (float)unaff_ESI[2]) &&
        (iVar4 = unaff_ESI[5], unaff_ESI[4] != iVar4)) && ((float)unaff_ESI[1] != 0.0)) {
      unaff_ESI[2] = 0;
      iVar3 = *unaff_ESI;
      if (*(int *)(local_8 + 8) == 0) {
        unaff_ESI[5] = 1;
        param_1 = 1.4013e-45;
        FUN_0082ef00(&param_1);
        if ((iVar1 != *(int *)(iVar3 + 0x38)) && (*(int *)(iVar1 + 0x10) != 0)) {
          iVar1 = *(int *)(*(int *)(iVar1 + 0x10) + 4);
          unaff_ESI[4] = 1;
          unaff_ESI[1] = iVar1;
          unaff_ESI[2] = 0;
          return;
        }
      }
      else {
        param_1 = (float)iVar4;
        FUN_0082ef00(&param_1);
        if ((iVar1 != *(int *)(iVar3 + 0x38)) && (*(int *)(iVar1 + 0x10) != 0)) {
          iVar1 = *(int *)(*(int *)(iVar1 + 0x10) + 4);
          unaff_ESI[4] = iVar4;
          unaff_ESI[1] = iVar1;
          unaff_ESI[2] = 0;
          return;
        }
      }
    }
  }
  return;
}

