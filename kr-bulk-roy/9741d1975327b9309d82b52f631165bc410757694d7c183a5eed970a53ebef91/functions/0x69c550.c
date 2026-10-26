
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0069c550(void)

{
  code *pcVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint in_ECX;
  int iVar8;
  int local_48;
  int local_44;
  undefined4 *local_40;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  void *pvStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c847;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (in_ECX < *(uint *)(DAT_00f94300 + 0x50d0)) {
    FUN_00542210();
    piVar2 = (int *)FUN_0050b4b0(in_ECX);
    iVar4 = 0;
    if ((int *)*piVar2 != (int *)0x0) {
      iVar4 = *(int *)*piVar2;
    }
    uVar3 = piVar2[2];
    if (*(uint *)(iVar4 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(iVar4 + 8);
    }
    puVar6 = *(undefined4 **)(*(int *)(iVar4 + 4) + uVar3 * 4);
    if (puVar6 != (undefined4 *)0x0) {
      local_40 = puVar6;
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 1;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      local_48 = puVar6[2];
      FUN_008438c0(&local_48);
      if (local_44 == DAT_00f8d91c) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(local_44 + 0x10);
      }
      if ((DAT_00f8d9a8 & 1) == 0) {
        DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
        local_c = 2;
        FUN_00523540();
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_00521080(&DAT_00f8d9bc);
        _atexit((_func_4879 *)&LAB_00bccc50);
        local_c = 0xffffffff;
      }
      local_44 = *(int *)(iVar4 + 0x20);
      FUN_008438c0(&local_44);
      if (local_48 == DAT_00f8d9b0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(local_48 + 0x10);
      }
      if (*(int *)(iVar4 + 8) == 0x1e) {
        if ((_DAT_00fb1314 & 1) == 0) {
          _DAT_00fb1314 = _DAT_00fb1314 | 1;
          _atexit((_func_4879 *)&DAT_00bccf10);
        }
        local_38 = *puVar6;
        local_34 = puVar6[1];
        local_3a = 0xaf;
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_3a,10);
        }
        local_44 = 0x196;
        iVar4 = FUN_005854b0();
        FUN_005740f0(&local_44);
        if (local_48 == *(int *)(iVar4 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (*(uint *)(local_48 + 0x24) < 8) {
          iVar4 = local_48 + 0x10;
        }
        else {
          iVar4 = *(int *)(local_48 + 0x10);
        }
        local_44 = 0x1a4;
        iVar5 = FUN_005854b0();
        FUN_005740f0(&local_44);
        if (local_48 == *(int *)(iVar5 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        puVar6 = (undefined4 *)(local_48 + 0x10);
        if (7 < *(uint *)(local_48 + 0x24)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        FUN_00404b10(0xca,puVar6,iVar4,0,0);
        ExceptionList = local_14;
        return;
      }
      iVar5 = 1;
      iVar4 = 0xca8;
      do {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 4;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if (iVar5 == 1) {
          iVar8 = iVar4 + 0xa50 + DAT_00f94300;
        }
        else {
          iVar8 = 0;
        }
        iVar7 = 1;
        if (0 < *(int *)(iVar8 + 0xca0)) {
          piVar2 = (int *)(iVar8 + 0x28);
          do {
            if ((piVar2[1] == 0) && (*piVar2 == 0)) {
              if (iVar7 != 0) {
                if ((_DAT_00fb1314 & 1) == 0) {
                  _DAT_00fb1314 = _DAT_00fb1314 | 1;
                  _atexit((_func_4879 *)&DAT_00bccf10);
                }
                local_38 = *local_40;
                local_3a = 0xad;
                local_34 = local_40[1];
                if (DAT_00fba798 != 0) {
                  ExceptionList = local_14;
                  return;
                }
                (**(code **)(*DAT_00fba854 + 0x10))(0,&local_3a,10);
                ExceptionList = pvStack_20;
                return;
              }
              break;
            }
            iVar7 = iVar7 + 1;
            piVar2 = piVar2 + 8;
          } while (iVar7 <= *(int *)(iVar8 + 0xca0));
        }
        iVar4 = iVar4 + 0xca8;
        iVar5 = iVar5 + 1;
      } while (iVar4 < 0x1950);
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 5;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        local_c = 0xffffffff;
      }
      local_40 = (undefined4 *)0x196;
      FUN_005740f0(&local_40);
      if (local_44 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 6;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        local_c = 0xffffffff;
      }
      local_40 = (undefined4 *)0xd;
      FUN_005740f0(&local_40);
      if (local_44 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (*(uint *)(local_44 + 0x24) < 8) {
        iVar4 = local_44 + 0x10;
      }
      else {
        iVar4 = *(int *)(local_44 + 0x10);
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 7;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      FUN_007532b0(&DAT_00f94810,iVar4,0,0);
    }
  }
  ExceptionList = local_14;
  return;
}

