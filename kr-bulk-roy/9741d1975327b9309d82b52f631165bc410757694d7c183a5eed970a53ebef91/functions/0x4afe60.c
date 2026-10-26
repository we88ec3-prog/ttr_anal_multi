
undefined4 FUN_004afe60(int param_1,uint param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  ushort *puVar8;
  float in_XMM0_Da;
  float local_50;
  ushort *local_4c;
  uint local_48;
  int local_44;
  float local_40;
  undefined4 uStack_3c;
  ushort local_38;
  ushort local_36;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined2 uStack_32;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936e1e;
  local_14 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    local_48 = 0;
  }
  else {
    local_48 = param_2 - 2 >> 3;
  }
  if (local_48 != 0) {
    puVar8 = (ushort *)(param_1 + 6);
    do {
      local_4c = puVar8;
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar5);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      uVar1 = puVar8[-2];
      local_50 = (float)(uint)uVar1;
      FUN_0082ef00(&local_50);
      if ((local_44 == DAT_00fab13c) || (piVar2 = *(int **)(local_44 + 0x10), piVar2 == (int *)0x0))
      {
        FUN_006edb60("InputUpdate: Character Not Exist.");
      }
      else {
        uStack_34 = (undefined1)puVar8[-1];
        local_36 = (short)*(char *)((int)puVar8 + -1) << 0xf;
        if ((*puVar8 != 0) && (puVar8[1] != 0)) {
          local_30 = (float)*puVar8;
          local_2c = (float)puVar8[1];
          piVar2[0x3a] = (int)local_30;
          piVar2[0x3b] = (int)local_2c;
          local_28 = (float)piVar2[0x3a] - (float)piVar2[0x28];
          local_50 = (float)piVar2[0x3b] - (float)piVar2[0x29];
          local_40 = local_28 * local_28 + local_50 * local_50;
          in_XMM0_Da = local_2c;
          local_24 = local_50;
          if (4.0 < local_40) {
            piVar2[0x36] = (int)local_28;
            piVar2[0x37] = (int)local_50;
            in_XMM0_Da = local_50;
            local_20 = local_28;
            local_1c = local_50;
          }
        }
        local_38 = uVar1;
        piVar6 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
        piVar7 = DAT_00fba7a4;
        if (piVar2 == piVar6) {
          if ((((*(ushort *)((int)DAT_00fba7a4 + 0x6a) & 0x8000) == 0) || ((local_36 & 0x8000) != 0)
              ) || (*(int *)(piVar2[0x56] + 8) == 0xd)) {
            DAT_00fba7a4[0x1d] = 0;
            if ((piVar7[0x1c] == 0) && (piVar2[0xea] != 0)) {
              piVar2[0xea] = 0;
            }
          }
          else {
            DAT_00fba7a4[0x1d] = 1;
            if (piVar2[0xea] == 0) {
              uStack_3c = CONCAT31(uStack_3c._1_3_,(char)piVar2[0x2c]);
              *(char *)(piVar2 + 0xe9) = (char)piVar2[0x2c];
              if ((piVar2[0xdc] != 0) && (piVar2[0x57] != 0)) {
                iVar3 = *(int *)(piVar2[0x57] + 4);
                FUN_00444a90(uStack_3c);
                (**(code **)(iVar3 + 0xc))(in_XMM0_Da);
                piVar7 = DAT_00fba7a4;
                puVar8 = local_4c;
              }
              piVar2[0xea] = 1;
            }
          }
        }
        (**(code **)(*piVar7 + 0x20))();
        pcVar4 = *(code **)(*piVar2 + 0x58);
        piVar2[0x38] = CONCAT22(local_36,local_38);
        *(undefined1 *)(piVar2 + 0x39) = uStack_34;
        (*pcVar4)(CONCAT22(uStack_32,CONCAT11(uStack_33,uStack_34)));
      }
      puVar8 = puVar8 + 4;
      local_48 = local_48 - 1;
    } while (local_48 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

