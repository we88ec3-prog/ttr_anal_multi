
void FUN_006c9cd0(int *param_1,char param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short *******pppppppsVar4;
  ushort in_CX;
  int *piVar5;
  short *******pppppppsVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_74 [7];
  char local_6d;
  int *local_6c;
  int *local_68;
  char local_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  int iStack_50;
  undefined4 uStack_48;
  uint local_44;
  short ******local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093bd5c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  ExceptionList = &local_14;
  local_6d = param_2;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar7 = DAT_00f94308;
  local_c = 0xffffffff;
  local_68 = (int *)(uint)in_CX;
  FUN_004a4cc0(&local_68);
  if ((local_6c != *(int **)(iVar7 + 0x14)) && (local_6c[4] != 0)) {
    *(ushort *)(param_1 + 0x5b) = in_CX;
    local_68 = (int *)(uint)in_CX;
    FUN_004dae30(&local_68);
    if (local_6c == *(int **)(iVar7 + 4)) {
      local_68 = (int *)(iVar7 + 0x30);
    }
    else {
      local_68 = local_6c + 4;
    }
    local_24 = 7;
    local_28 = 0;
    local_38[0] = (short ******)((uint)local_38[0] & 0xffff0000);
    FUN_004026e0(local_68 + 7,0,0xffffffff);
    local_60 = (uint)in_CX;
    local_c._0_1_ = 1;
    local_c._1_3_ = 0;
    local_64 = local_6d;
    FUN_004daea0(&local_60);
    if (((local_6c != *(int **)(iVar7 + 0x24)) && (FUN_00515a30(), local_60 != local_6c[5])) &&
       (local_6c = (int *)(local_60 + 0x10), local_6c != (int *)0x0)) {
      FUN_00404300(&DAT_00bfb894,1);
      FUN_00404300(L"<#FFFF00>",9);
      iVar7 = *local_6c;
      iVar2 = local_6c[1] - iVar7 >> 3;
      uVar8 = 0;
      if (iVar2 != 0) {
        if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        do {
          local_60 = *(uint *)(iVar7 + uVar8 * 8);
          FUN_005740f0(&local_60);
          uVar3 = FUN_006ca4f0(&local_58);
          local_c._0_1_ = 2;
          FUN_004041f0(uVar3,0,0xffffffff);
          local_c._0_1_ = 1;
          if (7 < local_44) {
            FUN_0089120c(local_58);
          }
          if (uVar8 != (local_6c[1] - *local_6c >> 3) - 1U) {
            FUN_00404300(&DAT_00c02b94,2);
          }
          iVar7 = *local_6c;
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)(local_6c[1] - iVar7 >> 3));
      }
      FUN_00404300(L"<br>",4);
    }
    FUN_006ca1d0(param_1);
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c._0_1_ = 3;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c._0_1_ = 1;
    }
    piVar5 = local_68;
    if (DAT_00f943e4 != 0) {
      local_5c = local_68[0xf];
      FUN_0082ef00(&local_5c);
    }
    FUN_00745060();
    (**(code **)(*(int *)param_1[0x57] + 200))();
    if (local_6d == '\0') {
      FUN_00757710();
    }
    else {
      if (7 < (uint)piVar5[5]) {
        piVar5 = (int *)*piVar5;
      }
      uVar3 = FUN_00498f10(piVar5);
      local_c._0_1_ = 4;
      FUN_00757800(uVar3);
      local_c._0_1_ = 1;
      if (7 < local_44) {
        FUN_0089120c(local_58);
      }
    }
    (**(code **)(*(int *)param_1[0x58] + 200))();
    pppppppsVar6 = (short *******)local_38[0];
    if (local_24 < 8) {
      pppppppsVar6 = local_38;
    }
    local_44 = 7;
    uStack_48 = 0;
    local_58 = (uint)local_58._2_2_ << 0x10;
    pppppppsVar4 = pppppppsVar6;
    do {
      sVar1 = *(short *)pppppppsVar4;
      pppppppsVar4 = (short *******)((int)pppppppsVar4 + 2);
    } while (sVar1 != 0);
    FUN_00402160(pppppppsVar6,(int)pppppppsVar4 - (int)((int)pppppppsVar6 + 2) >> 1);
    iVar7 = param_1[0x5a];
    local_c._0_1_ = 5;
    FUN_007578f0();
    FUN_00759ed0(iVar7 + 0xe8,&local_58,0x7b,0x7d);
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < local_44) {
      FUN_0089120c(local_58);
    }
    (**(code **)(*(int *)param_1[0x5a] + 200))();
    piVar5 = (int *)param_1[0x5a];
    (**(code **)(*piVar5 + 0x178))(&local_58);
    (**(code **)(*piVar5 + 0xbc))
              (piVar5[2],piVar5[3],piVar5[4],
               ((piVar5[0x30] + piVar5[0x31] * 2 + piVar5[0x2e]) - local_58) + piVar5[3] + iStack_50
              );
    local_60 = *(int *)(param_1[0x5a] + 0x14) + 0xf + param_1[3];
    (**(code **)(*param_1 + 0xbc))(param_1[2],param_1[3],param_1[4],local_60);
    if (7 < local_24) {
      FUN_0089120c(local_38[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

