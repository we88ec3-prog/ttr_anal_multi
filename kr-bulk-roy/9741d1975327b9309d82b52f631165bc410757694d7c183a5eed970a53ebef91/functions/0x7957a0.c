
void FUN_007957a0(void)

{
  float fVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *in_EAX;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *unaff_EDI;
  float10 fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined1 local_68 [12];
  undefined1 local_5c [12];
  undefined1 local_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  undefined1 local_28 [4];
  float local_24;
  undefined1 local_20 [4];
  float local_1c;
  undefined1 local_18 [4];
  float local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_24 = (float)(**(code **)(*in_EAX + 0x18))();
  puVar12 = (undefined4 *)((int)local_24 + -1);
  local_10 = puVar12;
  if (unaff_EDI == (undefined4 *)0x0) {
    local_2c = (float)(**(code **)(*in_EAX + 4))(local_28);
    iVar6 = (**(code **)(*in_EAX + 0x20))(puVar12);
    iVar9 = *(int *)((int)local_2c + 4);
    piVar7 = (int *)(**(code **)(*in_EAX + 4))(local_20);
    iVar10 = *piVar7;
    iVar8 = (**(code **)(*in_EAX + 0x20))();
    local_2c = (float)(iVar8 + ((iVar9 - iVar6) - iVar10));
    local_24 = (float)(int)local_2c;
    iVar9 = (**(code **)(*in_EAX + 0x20))(1);
    iVar10 = (**(code **)(*in_EAX + 0x20))();
    local_2c = local_24 + (float)(iVar9 - iVar10);
    local_8 = (undefined4 *)(local_2c * 0.5);
    local_c = (undefined4 *)(local_24 / (float)local_8);
    iVar9 = (**(code **)(*in_EAX + 0x20))(1);
    iVar10 = (**(code **)(*in_EAX + 0x20))();
    local_2c = (float)(iVar9 - iVar10);
    fVar1 = (float)(int)local_2c;
  }
  else if (unaff_EDI == puVar12) {
    local_2c = (float)(**(code **)(*in_EAX + 4))(local_20);
    iVar6 = (**(code **)(*in_EAX + 0x20))(puVar12);
    iVar9 = *(int *)((int)local_2c + 4);
    piVar7 = (int *)(**(code **)(*in_EAX + 4))(local_18);
    iVar10 = *piVar7;
    iVar8 = (**(code **)(*in_EAX + 0x20))(0);
    local_2c = (float)(iVar8 + ((iVar9 - iVar6) - iVar10));
    local_1c = (float)(int)local_2c;
    local_24 = (float)((int)local_24 + -2);
    iVar9 = (**(code **)(*in_EAX + 0x20))(local_24);
    iVar10 = (**(code **)(*in_EAX + 0x20))(local_10);
    local_2c = (float)(iVar10 - iVar9);
    local_8 = (undefined4 *)((local_1c + (float)(int)local_2c) * 0.5);
    local_c = (undefined4 *)(local_1c / (float)local_8);
    iVar9 = (**(code **)(*in_EAX + 0x20))(local_24);
    iVar10 = (**(code **)(*in_EAX + 0x20))(local_10);
    local_2c = (float)(iVar10 - iVar9);
    fVar1 = (float)(int)local_2c;
  }
  else {
    local_2c = (float)(**(code **)(*in_EAX + 0x20))((int)unaff_EDI + 1);
    iVar9 = (**(code **)(*in_EAX + 0x20))((int)unaff_EDI + -1);
    local_2c = (float)((int)local_2c - iVar9);
    local_8 = (undefined4 *)((float)(int)local_2c * 0.5);
    iVar9 = (**(code **)(*in_EAX + 0x20))((int)unaff_EDI + -1);
    iVar10 = (**(code **)(*in_EAX + 0x20))();
    local_2c = (float)(iVar10 - iVar9);
    local_c = (undefined4 *)((float)(int)local_2c / (float)local_8);
    iVar9 = (**(code **)(*in_EAX + 0x20))((int)unaff_EDI + 1);
    iVar10 = (**(code **)(*in_EAX + 0x20))();
    local_2c = (float)(iVar9 - iVar10);
    fVar1 = (float)(int)local_2c;
  }
  local_8 = (undefined4 *)(fVar1 / (float)local_8);
  if ((undefined4 *)((in_EAX[7] - in_EAX[6]) / 0x44) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  iVar10 = (int)unaff_EDI * 0x44;
  fVar13 = (float10)FUN_004ff540(*(undefined4 *)(iVar10 + 0x1c + in_EAX[6]));
  fVar1 = (float)fVar13;
  iVar9 = in_EAX[6];
  local_c = (undefined4 *)(((float)local_c + fVar1) - (float)local_c * fVar1);
  local_8 = (undefined4 *)(((float)local_8 + fVar1) - (float)local_8 * fVar1);
  fVar1 = 1.0 - *(float *)(iVar10 + 0x1c + iVar9);
  fVar4 = (1.0 - *(float *)(iVar10 + 0x18 + iVar9)) * 0.5;
  fVar3 = 1.0 - *(float *)(iVar10 + 0x20 + iVar9);
  fVar5 = fVar1 * fVar4;
  fVar4 = fVar4 * (2.0 - fVar1);
  local_2c = (float)local_c * (2.0 - fVar3) * fVar5;
  local_24 = fVar4 * fVar3 * (float)local_c;
  local_1c = (float)local_8 * (2.0 - fVar3) * fVar4;
  pcVar2 = *(code **)(*in_EAX + 0x1c);
  local_14 = (float)local_8 * fVar5 * fVar3;
  if (unaff_EDI == (undefined4 *)0x0) {
    local_c = (undefined4 *)(*pcVar2)(local_50,1);
    local_8 = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_5c);
    puVar11 = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_68,local_10);
    uVar16 = *local_c;
    uVar17 = local_c[1];
    uVar18 = local_c[2];
    uVar14 = *local_8;
    uVar15 = local_8[1];
    puVar12 = local_8;
  }
  else if (unaff_EDI == local_10) {
    local_10 = (undefined4 *)(*pcVar2)(local_68,0);
    local_c = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_5c);
    puVar11 = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_50,(int)unaff_EDI + -1);
    uVar16 = *local_10;
    uVar17 = local_10[1];
    uVar18 = local_10[2];
    uVar14 = *local_c;
    uVar15 = local_c[1];
    puVar12 = local_c;
  }
  else {
    local_10 = (undefined4 *)(*pcVar2)(local_68,(int)unaff_EDI + 1);
    local_c = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_5c);
    puVar11 = (undefined4 *)(**(code **)(*in_EAX + 0x1c))(local_50,(int)unaff_EDI + -1);
    uVar16 = *local_10;
    uVar17 = local_10[1];
    uVar18 = local_10[2];
    uVar14 = *local_c;
    uVar15 = local_c[1];
    puVar12 = local_c;
  }
  FUN_00795ee0(*puVar11,puVar11[1],puVar11[2],uVar14,uVar15,puVar12[2],uVar16,uVar17,uVar18,local_2c
               ,local_24,local_1c,local_14);
  iVar9 = in_EAX[6];
  if ((undefined4 *)((in_EAX[7] - iVar9) / 0x44) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(undefined4 *)(iVar10 + 0x2c + iVar9) = local_38;
  *(undefined4 *)(iVar10 + 0x30 + iVar9) = local_34;
  *(undefined4 *)(iVar10 + 0x34 + iVar9) = local_30;
  iVar9 = in_EAX[6];
  if ((undefined4 *)((in_EAX[7] - iVar9) / 0x44) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(undefined4 *)(iVar10 + 0x38 + iVar9) = local_44;
  *(undefined4 *)(iVar10 + 0x3c + iVar9) = local_40;
  *(undefined4 *)(iVar10 + 0x40 + iVar9) = local_3c;
  return;
}

