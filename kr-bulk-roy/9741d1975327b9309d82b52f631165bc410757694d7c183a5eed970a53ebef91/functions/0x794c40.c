
void FUN_00794c40(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_EAX;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint unaff_EDI;
  float10 fVar10;
  undefined1 local_28 [4];
  float local_24;
  undefined1 local_20 [4];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_14 = (float)(**(code **)(*in_EAX + 0x18))();
  uVar1 = (int)local_14 - 1;
  local_10 = (float)uVar1;
  if (unaff_EDI == 0) {
    local_18 = (float)(**(code **)(*in_EAX + 4))(local_28);
    iVar5 = (**(code **)(*in_EAX + 0x20))(uVar1);
    iVar8 = *(int *)((int)local_18 + 4);
    piVar6 = (int *)(**(code **)(*in_EAX + 4))(local_20);
    iVar9 = *piVar6;
    iVar7 = (**(code **)(*in_EAX + 0x20))();
    local_18 = (float)(iVar7 + ((iVar8 - iVar5) - iVar9));
    local_14 = (float)(int)local_18;
    iVar8 = (**(code **)(*in_EAX + 0x20))(1);
    iVar9 = (**(code **)(*in_EAX + 0x20))();
    local_18 = local_14 + (float)(iVar8 - iVar9);
    local_8 = local_18 * 0.5;
    local_c = local_14 / local_8;
    iVar8 = (**(code **)(*in_EAX + 0x20))(1);
    iVar9 = (**(code **)(*in_EAX + 0x20))();
    local_18 = (float)(iVar8 - iVar9);
    fVar2 = (float)(int)local_18;
  }
  else if (unaff_EDI == uVar1) {
    local_18 = (float)(**(code **)(*in_EAX + 4))(local_28);
    iVar5 = (**(code **)(*in_EAX + 0x20))(uVar1);
    iVar8 = *(int *)((int)local_18 + 4);
    piVar6 = (int *)(**(code **)(*in_EAX + 4))(local_20);
    iVar9 = *piVar6;
    iVar7 = (**(code **)(*in_EAX + 0x20))(0);
    local_18 = (float)(iVar7 + ((iVar8 - iVar5) - iVar9));
    local_c = (float)(int)local_18;
    local_14 = (float)((int)local_14 + -2);
    iVar8 = (**(code **)(*in_EAX + 0x20))(local_14);
    iVar9 = (**(code **)(*in_EAX + 0x20))(local_10);
    local_18 = (float)(iVar9 - iVar8);
    local_8 = (local_c + (float)(int)local_18) * 0.5;
    local_c = local_c / local_8;
    iVar8 = (**(code **)(*in_EAX + 0x20))(local_14);
    iVar9 = (**(code **)(*in_EAX + 0x20))(local_10);
    local_18 = (float)(iVar9 - iVar8);
    fVar2 = (float)(int)local_18;
  }
  else {
    local_18 = (float)(**(code **)(*in_EAX + 0x20))(unaff_EDI + 1);
    iVar8 = (**(code **)(*in_EAX + 0x20))(unaff_EDI - 1);
    local_18 = (float)((int)local_18 - iVar8);
    local_8 = (float)(int)local_18 * 0.5;
    iVar8 = (**(code **)(*in_EAX + 0x20))();
    iVar9 = (**(code **)(*in_EAX + 0x20))(unaff_EDI - 1);
    local_18 = (float)(iVar8 - iVar9);
    local_c = (float)(int)local_18 / local_8;
    iVar8 = (**(code **)(*in_EAX + 0x20))();
    iVar9 = (**(code **)(*in_EAX + 0x20))(unaff_EDI + 1);
    local_18 = (float)(iVar9 - iVar8);
    fVar2 = (float)(int)local_18;
  }
  local_8 = fVar2 / local_8;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x2c) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  iVar9 = unaff_EDI * 0x2c;
  fVar10 = (float10)FUN_004ff540(*(undefined4 *)(iVar9 + 0x14 + in_EAX[6]));
  fVar2 = (float)fVar10;
  iVar8 = in_EAX[6];
  local_c = (local_c + fVar2) - local_c * fVar2;
  local_8 = (local_8 + fVar2) - local_8 * fVar2;
  fVar2 = 1.0 - *(float *)(iVar9 + 0x14 + iVar8);
  local_1c = (1.0 - *(float *)(iVar9 + 0x10 + iVar8)) * 0.5;
  fVar3 = 1.0 - *(float *)(iVar9 + 0x18 + iVar8);
  local_24 = 2.0 - fVar3;
  fVar4 = fVar2 * local_1c;
  local_1c = local_1c * (2.0 - fVar2);
  local_14 = local_c * local_24 * fVar4;
  local_c = local_1c * fVar3 * local_c;
  local_18 = local_8 * local_24 * local_1c;
  local_8 = local_8 * fVar4 * fVar3;
  if (unaff_EDI == 0) {
    fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))(local_10);
    local_24 = (float)fVar10;
    fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))();
    iVar8 = 1;
  }
  else {
    fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))(unaff_EDI - 1);
    local_24 = (float)fVar10;
    fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))();
    if ((float)unaff_EDI == local_10) {
      iVar8 = 0;
    }
    else {
      iVar8 = unaff_EDI + 1;
    }
  }
  local_10 = (float)fVar10;
  local_1c = local_10 - local_24;
  fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar8);
  local_24 = (float)(fVar10 - (float10)local_10);
  local_14 = local_1c * local_14 + local_24 * local_c;
  local_18 = local_1c * local_18 + local_8 * local_24;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x2c) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(iVar9 + 0x24 + in_EAX[6]) = local_14;
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x2c) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(iVar9 + 0x28 + in_EAX[6]) = local_18;
  return;
}

