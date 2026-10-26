
undefined4 FUN_004afb80(int param_1,uint param_2,short param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  float *pfVar9;
  float *pfStack_54;
  uint local_4c;
  uint local_48;
  int local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936e1e;
  local_14 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    local_4c = 0;
  }
  else {
    local_4c = (param_2 - 2) / 10;
  }
  if (local_4c != 0) {
    pfVar9 = (float *)(param_1 + 4);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar7);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_48 = (uint)*(ushort *)((int)pfVar9 + -2);
      FUN_0082ef00(&local_48);
      if ((local_44 == DAT_00fab13c) || (piVar2 = *(int **)(local_44 + 0x10), piVar2 == (int *)0x0))
      {
        FUN_006edb60("[PosUpdate]: Cannot Found In CharList");
      }
      else {
        piVar8 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
        if (piVar2 == piVar8) {
          DAT_00fba7a4[0x1d] = 0;
        }
        piVar2[0x35] = 0;
        piVar2[0x3a] = (int)*pfVar9;
        piVar2[0x3b] = (int)pfVar9[1];
        if (param_3 == 0x16) {
          iVar6 = piVar2[0x39];
          iVar3 = piVar2[0x38];
          uStack_40 = 0;
          uStack_3c = 0;
          piVar2[0x36] = 0;
          piVar8 = DAT_00fba7a4;
          piVar2[0x37] = 0;
          uStack_1c = CONCAT31(uStack_1c._1_3_,(char)iVar6);
          (**(code **)(*piVar8 + 0x20))();
          pcVar4 = *(code **)(*piVar2 + 0x58);
          piVar2[0x38] = iVar3;
          *(char *)(piVar2 + 0x39) = (char)iVar6;
          (*pcVar4)(uStack_1c);
          fStack_2c = *pfStack_54;
          fStack_28 = pfStack_54[1];
          (**(code **)(*piVar2 + 0x44))(&fStack_2c,1);
          bVar1 = *(byte *)(piVar2 + 0x2c);
          if (((piVar2[0xea] == 0) && (*(byte *)(piVar2 + 0xe9) = bVar1, piVar2[0xdc] != 0)) &&
             (iVar3 = piVar2[0x57], iVar3 != 0)) {
            if ((DAT_00fb7c18 & 1) == 0) {
              DAT_00fb7c18 = DAT_00fb7c18 | 1;
              FUN_004449d0();
            }
            (**(code **)(*(int *)(iVar3 + 4) + 0xc))((&DAT_00fb7c20)[bVar1]);
          }
        }
        else {
          fVar5 = *pfVar9 - (float)piVar2[0x28];
          if ((*(ushort *)((int)piVar2 + 0xe2) & 0x8000) == 0) {
            fStack_2c = pfVar9[1] - (float)piVar2[0x29];
            piVar2[0x36] = (int)fVar5;
            piVar2[0x37] = (int)fStack_2c;
            fStack_30 = fVar5;
          }
          else {
            fStack_34 = pfVar9[1] - (float)piVar2[0x29];
            piVar2[0x36] = (int)fVar5;
            piVar2[0x37] = (int)fStack_34;
            fStack_38 = fVar5;
          }
          bVar1 = *(byte *)(piVar2 + 0x2c);
          if (((piVar2[0xea] == 0) && (*(byte *)(piVar2 + 0xe9) = bVar1, piVar2[0xdc] != 0)) &&
             (iVar3 = piVar2[0x57], iVar3 != 0)) {
            if ((DAT_00fb7c18 & 1) == 0) {
              DAT_00fb7c18 = DAT_00fb7c18 | 1;
              FUN_004449d0();
            }
            (**(code **)(*(int *)(iVar3 + 4) + 0xc))((&DAT_00fb7c20)[bVar1]);
          }
        }
      }
      pfVar9 = (float *)((int)pfVar9 + 10);
      local_4c = local_4c - 1;
    } while (local_4c != 0);
  }
  ExceptionList = local_14;
  return 0;
}

