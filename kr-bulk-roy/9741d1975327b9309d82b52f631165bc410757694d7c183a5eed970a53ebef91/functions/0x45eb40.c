
void FUN_0045eb40(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int *local_4c;
  int local_48;
  int local_44;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009341b0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_4c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  local_4c = in_ECX;
  FUN_007e8a90(&local_48,in_ECX[0x40] + 4);
  uVar7 = 0;
  local_c = 0;
  uVar6 = local_44 - local_48 >> 2;
  if (*(int *)(in_ECX[0x3c] + 0xcc) != 0) {
    FUN_00408920(*(int *)(in_ECX[0x3c] + 0xcc),uVar6);
  }
  if (uVar6 != 0) {
    do {
      iVar9 = *(int *)(in_ECX[0x3c] + 0xcc);
      if (((iVar9 == 0) || ((int)uVar7 < 0)) ||
         (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= (int)uVar7)) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(*(int *)(iVar9 + 0xa8) + uVar7 * 4);
      }
      if (uVar6 <= uVar7) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript",uVar3);
      }
      puVar1 = *(undefined4 **)(local_48 + uVar7 * 4);
      uVar4 = puVar1[1];
      *(undefined4 *)(iVar9 + 0x250) = *puVar1;
      *(undefined4 *)(iVar9 + 0x254) = uVar4;
      FUN_0045e750();
      FUN_0045e750();
      uVar7 = uVar7 + 1;
      in_ECX = local_4c;
    } while (uVar7 < uVar6);
  }
  piVar2 = (int *)in_ECX[0x3c];
  piVar5 = (int *)piVar2[0x19];
  piVar8 = (int *)*piVar5;
  local_4c = piVar5;
  if (piVar8 != piVar5) {
    do {
      iVar9 = piVar8[2];
      if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
        piVar5 = local_4c;
      }
      piVar8 = (int *)*piVar8;
    } while (piVar8 != piVar5);
  }
  (**(code **)(*piVar2 + 0x128))();
  (**(code **)(*(int *)in_ECX[0x3c] + 200))();
  uVar4 = FUN_00412df0();
  local_c._0_1_ = 1;
  FUN_00757800(uVar4);
  local_c = (uint)local_c._1_3_ << 8;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  (**(code **)(*(int *)in_ECX[0x3d] + 200))();
  if (local_48 != 0) {
    FUN_0089120c(local_48);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_4c);
  return;
}

