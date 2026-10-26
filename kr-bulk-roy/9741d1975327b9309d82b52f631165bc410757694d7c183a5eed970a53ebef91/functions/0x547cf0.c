
undefined4 FUN_00547cf0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *in_ECX;
  int *piVar10;
  float10 fVar11;
  float local_34;
  int local_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00939cec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX[1] != 0) {
    iVar5 = in_ECX[3];
    if (iVar5 != 0) {
      uVar1 = *(undefined4 *)(iVar5 + 0xa0);
      uVar2 = *(undefined4 *)(iVar5 + 0xa4);
      fVar3 = *(float *)(iVar5 + 0xa8);
      if ((*(int *)(iVar5 + 0x15c) == 0) || (*(int *)(iVar5 + 0x370) == 0)) {
        local_34 = 0.0;
      }
      else {
        fVar11 = (float10)FUN_007a7100(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
        local_34 = (float)fVar11;
      }
      uVar8 = DAT_00fb8828 & 1;
      iVar6 = in_ECX[0x2e];
      *(undefined4 *)(iVar6 + 0xc) = uVar1;
      *(undefined4 *)(iVar6 + 0x10) = uVar2;
      *(float *)(iVar6 + 0x14) = local_34 + 2.0 + fVar3;
      fVar3 = *(float *)(iVar5 + 0xb4);
      if (uVar8 == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
      }
      piVar10 = (int *)in_ECX[0x2e];
      fVar3 = DAT_00fb90bc * fVar3;
      piVar10[1] = (int)fVar3;
      iVar5 = *piVar10;
      if ((iVar5 != 0) && (*(float *)(iVar5 + 0x10) = fVar3, *(int *)(iVar5 + 4) != 0)) {
        FUN_0077ef50(fVar3,fVar3,fVar3);
      }
      FUN_0079c650(param_1);
    }
    piVar10 = in_ECX + 0x2f;
    local_30 = 3;
    do {
      in_ECX = in_ECX + 3;
      piVar7 = (int *)*in_ECX;
      if ((piVar7 != (int *)0x0) && (*piVar10 != 0)) {
        iVar5 = *(int *)*piVar10;
        puVar9 = (undefined4 *)(**(code **)(*piVar7 + 0x4c))();
        (**(code **)(iVar5 + 0x10))(*puVar9,puVar9[1],puVar9[2]);
        bVar4 = *(byte *)(piVar7 + 0xe9);
        if ((DAT_00fb7c18 & 1) == 0) {
          DAT_00fb7c18 = DAT_00fb7c18 | 1;
          FUN_004449d0();
        }
        (**(code **)(*(int *)*piVar10 + 0xc))((&DAT_00fb7c20)[bVar4]);
        fVar3 = (float)piVar7[0x2d];
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
        }
        (**(code **)(*(int *)*piVar10 + 8))(DAT_00fb90bc * fVar3);
        FUN_0079cbd0();
        (**(code **)(*(int *)*piVar10 + 4))(param_1);
      }
      piVar10 = piVar10 + 1;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

