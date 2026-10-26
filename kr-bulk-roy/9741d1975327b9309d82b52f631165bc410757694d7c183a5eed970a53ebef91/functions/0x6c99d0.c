
void FUN_006c99d0(void)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  short *******pppppppsVar6;
  int in_ECX;
  short *******pppppppsVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_6c [4];
  uint local_68;
  uint local_64;
  int local_60;
  short ******local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  undefined4 uStack_30;
  uint local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093bdb6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  local_60 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar8 = DAT_00f94308;
  local_c = 0xffffffff;
  uVar1 = *(ushort *)(in_ECX + 0x16c);
  local_64 = (uint)uVar1;
  FUN_004a4cc0(&local_64);
  if (((local_68 != *(uint *)(iVar8 + 0x14)) && (*(int *)(local_68 + 0x10) != 0)) &&
     (*(int *)(*(int *)(local_68 + 0x10) + 4) == 0)) {
    local_68 = (uint)uVar1;
    FUN_004dae30(&local_68);
    iVar4 = local_64 + 0x10;
    if (local_64 == *(uint *)(iVar8 + 4)) {
      iVar4 = iVar8 + 0x30;
    }
    local_5c[0] = (short ******)((uint)local_5c[0] & 0xffff0000);
    local_48 = 7;
    local_4c = 0;
    FUN_004026e0(iVar4 + 0x1c,0,0xffffffff);
    local_c = 1;
    piVar3 = (int *)FUN_004dade0(*(undefined2 *)(in_ECX + 0x16c),0);
    if (piVar3 != (int *)0x0) {
      FUN_00404300(&DAT_00bfb894,1);
      FUN_00404300(L"<#FFFF00>",9);
      iVar8 = *piVar3;
      iVar4 = piVar3[1] - iVar8 >> 3;
      uVar9 = 0;
      if (iVar4 != 0) {
        if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        do {
          local_68 = *(uint *)(iVar8 + uVar9 * 8);
          FUN_005740f0(&local_68);
          uVar5 = FUN_006ca4f0(&local_40);
          local_c._0_1_ = 2;
          FUN_004041f0(uVar5,0,0xffffffff);
          local_c = CONCAT31(local_c._1_3_,1);
          if (7 < local_2c) {
            FUN_0089120c(local_40);
          }
          if (uVar9 != (piVar3[1] - *piVar3 >> 3) - 1U) {
            FUN_00404300(&DAT_00c02b94,2);
          }
          iVar8 = *piVar3;
          uVar9 = uVar9 + 1;
        } while (uVar9 < (uint)(piVar3[1] - iVar8 >> 3));
      }
      FUN_00404300(L"<br>",4);
      in_ECX = local_60;
    }
    FUN_006ca1d0(in_ECX);
    pppppppsVar7 = (short *******)local_5c[0];
    if (local_48 < 8) {
      pppppppsVar7 = local_5c;
    }
    local_40 = (uint)local_40._2_2_ << 0x10;
    local_2c = 7;
    uStack_30 = 0;
    pppppppsVar6 = pppppppsVar7;
    do {
      sVar2 = *(short *)pppppppsVar6;
      pppppppsVar6 = (short *******)((int)pppppppsVar6 + 2);
    } while (sVar2 != 0);
    FUN_00402160(pppppppsVar7,(int)pppppppsVar6 - (int)((int)pppppppsVar7 + 2) >> 1);
    iVar8 = *(int *)(in_ECX + 0x168);
    local_c._0_1_ = 3;
    FUN_007578f0();
    FUN_00759ed0(iVar8 + 0xe8,&local_40,0x7b,0x7d);
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < local_2c) {
      FUN_0089120c(local_40);
    }
    (**(code **)(**(int **)(local_60 + 0x168) + 200))();
    if (7 < local_48) {
      FUN_0089120c(local_5c[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

