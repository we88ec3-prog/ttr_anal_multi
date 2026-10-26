
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ae4d0(int param_1,uint param_2)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  ushort *puVar9;
  undefined1 *puVar10;
  undefined1 auStack_14c [4];
  int *local_148;
  int *local_144;
  int *local_140;
  int local_13c;
  uint local_138;
  uint local_134;
  int local_130;
  int iStack_12c;
  int iStack_128;
  undefined4 local_124;
  undefined4 local_120;
  int local_11c;
  undefined1 local_118;
  int *local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 auStack_104 [28];
  undefined1 auStack_e8 [204];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00940cdb;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_14c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffea8;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    local_134 = 0;
  }
  else {
    local_134 = (param_2 - 2) / 0x1a;
  }
  local_138 = 0;
  if (local_134 != 0) {
    puVar9 = (ushort *)(param_1 + 6);
    do {
      local_13c = 1;
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar3);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_144 = (int *)(uint)puVar9[-2];
      piVar4 = (int *)FUN_0082ef00(&local_144);
      if (*piVar4 == DAT_00fab13c) {
        piVar4 = (int *)(((byte)puVar9[-1] - 1 | (uint)(byte)puVar9[-2] << 8) << 0x10 |
                        (uint)*puVar9);
        local_140 = piVar4;
        switch((uint)(byte)puVar9[-2]) {
        case 0:
          local_148 = (int *)FUN_00891268(0x444);
          local_c = 1;
          if (local_148 == (int *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)FUN_004cd6f0(local_148,*(undefined4 *)(puVar9 + 7));
          }
          local_c = 0xffffffff;
          iVar7 = FUN_00404ba0();
          if (*(int *)(puVar9 + 7) == *(int *)(iVar7 + 0x5f50)) {
            iVar7 = FUN_00404ba0();
            uVar5 = (uint)*puVar9;
            if (((uVar5 < 10) &&
                (piVar8 = (int *)(uVar5 * 0x210 + *(int *)(iVar7 + 0x6924)), piVar8 != (int *)0x0))
               && (piVar8[0x17] == 0)) {
              (**(code **)(*piVar8 + 4))(uVar5);
            }
          }
          break;
        case 1:
          local_148 = (int *)FUN_00891268(0x434);
          local_c = 2;
          if (local_148 == (int *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)FUN_004d1710(local_148);
          }
          local_c = 0xffffffff;
          piVar4 = (int *)FUN_00891268(0x48);
          local_c = 3;
          local_148 = piVar4;
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4[1] = (uint)*(ushort *)(piVar6 + 1);
            *piVar4 = 7;
            piVar4[2] = 1;
            *(undefined1 *)(piVar4 + 3) = 1;
            piVar4[4] = *(int *)(puVar9 + 1);
            piVar4[5] = *(int *)(puVar9 + 3);
            local_120 = 0;
            piVar4[8] = 0;
            local_124 = 0;
            piVar4[6] = 0;
            piVar4[7] = 0;
            piVar4[0xe] = 7;
            piVar4[0xd] = 0;
            *(undefined2 *)(piVar4 + 9) = 0;
            FUN_00402160(&DAT_00bed1fc,0);
            piVar4[0x10] = 0;
            piVar4[0x11] = 0;
          }
          local_c = 0xffffffff;
          if ((_DAT_00fdf3c0 & 1) == 0) {
            _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
            DAT_00fdf3c4 = 0;
            _atexit((_func_4879 *)&DAT_00bcdf50);
          }
          FUN_0056f5c0(DAT_00fdf3c4,piVar4);
          uVar5 = DAT_00fb75b0 & 1;
          piVar6[0x109] = (uint)*(byte *)((int)puVar9 + 0x13);
          if (uVar5 == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_c = 4;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_c = 0xffffffff;
          }
          local_144 = local_140;
          iVar7 = FUN_004f7a70();
          piVar4 = local_140;
          if (*(char *)(iVar7 + 0x61) == '\0') {
            local_13c = 0;
            if (piVar6[0xda] != 0) {
              *(undefined4 *)(piVar6[0xda] + 0x24) = 0;
            }
          }
          else {
            local_13c = 1;
          }
          break;
        default:
          goto switchD_004ae5dd_caseD_2;
        case 6:
          local_148 = (int *)FUN_00891268(0x42c);
          local_c = 5;
          if (local_148 == (int *)0x0) {
            local_144 = (int *)0x0;
          }
          else {
            local_144 = (int *)FUN_004d2120(local_148);
          }
          if ((DAT_00fe18c8 & 1) == 0) {
            DAT_00fe18c8 = DAT_00fe18c8 | 1;
            local_c = 6;
            FUN_0053f970();
            _atexit((_func_4879 *)&LAB_00bce810);
          }
          local_c = 0xffffffff;
          uVar1 = *puVar9;
          local_148 = (int *)(uint)uVar1;
          FUN_008438c0(&local_148);
          piVar6 = local_144;
          if (local_11c != DAT_00fe18e0) {
            local_118 = *(undefined1 *)((int)puVar9 + -3);
            local_110 = *(undefined4 *)(local_11c + 0x10);
            local_10c = DAT_00fe18ec;
            local_114 = (int *)(uint)uVar1;
            FUN_0053eba0();
            piVar6 = local_144;
            piVar4 = local_140;
          }
          break;
        case 7:
          local_148 = (int *)FUN_00891268(0x428);
          local_c = 7;
          if (local_148 == (int *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)FUN_004d1060(local_148);
          }
          local_c = 0xffffffff;
          piVar6[0x108] = (uint)*(byte *)((int)puVar9 + 0x13);
        }
        if (piVar6 == (int *)0x0) {
switchD_004ae5dd_caseD_2:
                    /* WARNING: Subroutine does not return */
          FUN_006edc70(&DAT_00c069c0);
        }
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_c = 8;
          FUN_0079cf40();
          _atexit((_func_4879 *)&LAB_00bcdb80);
          local_c = 0xffffffff;
        }
        local_148 = (int *)(uint)*puVar9;
        FUN_00515790(&local_148);
        if ((local_130 == DAT_00fc0e94) || (*(int *)(*(int *)(local_130 + 0x10) + 0x54) == 0)) {
          iVar7 = (**(code **)(*DAT_00fba7a4 + 0x20))();
          if (iVar7 != 0) {
            local_148 = *(int **)(iVar7 + 0x9c);
            if ((DAT_00fab22c & 1) == 0) {
              DAT_00fab22c = DAT_00fab22c | 1;
              local_c = 9;
              FUN_004dec90();
              _atexit((_func_4879 *)&LAB_00bcce30);
              local_c = 0xffffffff;
            }
            FUN_008438c0(&local_148);
            if (((iStack_128 != DAT_00fab14c) && (*(int *)(iStack_128 + 0x10) != 0)) &&
               (4 < *(byte *)(*(int *)(iStack_128 + 0x10) + 0x20))) {
              FUN_004b7c80(L"Load Error: [%d] Does not exist in preload list",*puVar9);
              FUN_00402250(auStack_e8);
              puVar10 = auStack_104;
              local_c = 10;
              FUN_0040f8c0(puVar10);
              FUN_004d6b30(puVar10);
              local_c = 0xffffffff;
              FUN_004fa440();
              piVar4 = local_140;
            }
          }
          if ((DAT_00fc0e40 & 1) == 0) {
            DAT_00fc0e40 = DAT_00fc0e40 | 1;
            local_c = 0xb;
            FUN_00540770();
            _atexit((_func_4879 *)&LAB_00bcdb60);
            local_c = 0xffffffff;
          }
          FUN_00541610(*puVar9);
        }
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 0xc;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = 0xffffffff;
        }
        local_148 = piVar4;
        iVar7 = FUN_004f7a70();
        pcVar2 = *(code **)(piVar6[0x3c] + 8);
        piVar6[0x107] = (uint)*(byte *)(iVar7 + 0x61);
        (*pcVar2)(*(undefined1 *)((int)puVar9 + 0x15));
        piVar6[0x27] = *(int *)(puVar9 + 7);
        piVar6[0x24] = (uint)(byte)puVar9[10];
        *(ushort *)(piVar6 + 1) = puVar9[-2];
        (**(code **)(*piVar6 + 0x3c))(piVar4);
        (**(code **)(*piVar6 + 0x44))(puVar9 + 1,1);
        (**(code **)(*piVar6 + 0x58))((char)puVar9[9]);
        (**(code **)(*piVar6 + 0x5c))(*(undefined4 *)(puVar9 + 5));
        if (*(char *)((int)puVar9 + 0x15) == '\x18') {
          *(undefined1 *)(piVar6 + 0x2f) = 1;
        }
        (**(code **)(*piVar6 + 0x30))();
        if ((char)puVar9[-2] == '\x01') {
          if ((local_13c == 0) && (piVar6[0xda] != 0)) {
            *(undefined4 *)(piVar6[0xda] + 0x24) = 0;
          }
          piVar6[0x10a] = (uint)(*(char *)((int)puVar9 + 0x13) == '\x04');
        }
        else if (((char)puVar9[-2] == '\x06') && (piVar6[0xda] != 0)) {
          *(undefined4 *)(piVar6[0xda] + 0x24) = 0;
        }
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 0xd;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        FUN_004dff30(&DAT_00fab130);
        if (*(int *)(puVar9 + 7) != 0) {
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 0xe;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          local_148 = *(int **)(puVar9 + 7);
          FUN_008438c0(&local_148);
          if ((((iStack_12c != DAT_00fab14c) && (*(int *)(iStack_12c + 0x10) != 0)) &&
              (*(int *)(*(int *)(iStack_12c + 0x10) + 4) == 0)) &&
             (FUN_004c6e50(), (char)piVar6[1] == '\0')) {
            piVar6[0x26] = 1;
          }
        }
        if (*(char *)((int)puVar9 + 0x13) == '\x04') {
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 0xf;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          local_148 = DAT_00fab134;
          FUN_0053dda0();
          *(ushort *)(local_148 + 0xc) = puVar9[-2];
        }
        else if (*(char *)((int)puVar9 + 0x13) == '\x06') {
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 0x10;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          *(ushort *)((int)DAT_00fab134 + 0x32) = puVar9[-2];
        }
      }
      local_138 = local_138 + 1;
      puVar9 = puVar9 + 0xd;
    } while (local_138 < local_134);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_14c);
  return;
}

