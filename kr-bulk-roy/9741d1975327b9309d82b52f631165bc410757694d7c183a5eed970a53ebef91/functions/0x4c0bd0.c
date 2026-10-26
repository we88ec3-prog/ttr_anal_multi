
void FUN_004c0bd0(int param_1)

{
  uint *puVar1;
  char cVar2;
  int ***pppiVar3;
  int *piVar4;
  int **ppiVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  uint *local_154;
  int **local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int *local_13c;
  int *local_138;
  long local_134;
  long local_130;
  int **local_124;
  int **local_120;
  undefined4 local_114;
  uint local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_40;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009387a1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_154;
  ExceptionList = &local_14;
  local_14c = param_1;
  local_108 = 0;
  local_104 = 0;
  FUN_0071bc20(DAT_00d61f20 ^ (uint)&stack0xfffffea0);
  local_40 = 0;
  local_28 = 0xf;
  local_2c = 0;
  local_3c = local_3c & 0xffffff00;
  local_c = 0;
  local_110 = 0xf;
  local_114 = 0;
  local_124 = (int **)((uint)local_124 & 0xffffff00);
  FUN_00402a70("Table/ExpeditionInfo.xml",0x18);
  local_c = CONCAT31(local_c._1_3_,1);
  pppiVar3 = (int ***)local_124;
  if (local_110 < 0x10) {
    pppiVar3 = &local_124;
  }
  piVar4 = (int *)FUN_00714770(pppiVar3,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) {
    cVar2 = '\0';
  }
  else {
    (**(code **)(*piVar4 + 0x38))();
    uVar6 = (**(code **)(*piVar4 + 0x2c))();
    cVar2 = FUN_00499340(uVar6);
    (**(code **)(*piVar4 + 4))();
  }
  local_c = local_c & 0xffffff00;
  if (0xf < local_110) {
    FUN_0089120c(local_124);
  }
  if (cVar2 == '\0') {
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c);
    }
  }
  else {
    FUN_0071a090(&local_124);
    local_c = CONCAT31(local_c._1_3_,2);
    local_150 = local_124;
    pppiVar3 = (int ***)local_124;
    if (local_124 != local_120) {
      do {
        local_13c = *local_150;
        local_138 = local_150[1];
        lVar7 = 0;
        if ((int **)local_138 == (int **)0x0) {
          ppiVar5 = &local_13c;
        }
        else {
          local_140 = 0;
          ppiVar5 = (int **)&local_140;
        }
        puVar1 = (uint *)*ppiVar5;
        if ((puVar1 != (uint *)0x0) && ((*puVar1 & 7) == 1)) {
          local_154 = puVar1;
          FUN_0071baa0(&DAT_00c071fc);
          if (local_144 != 0) {
            if (*(char **)(local_144 + 8) == (char *)0x0) {
              lVar7 = 0;
            }
            else {
              lVar7 = _strtol(*(char **)(local_144 + 8),(char **)0x0,10);
            }
          }
          lVar8 = 0;
          FUN_0071baa0("eligibleType");
          if (local_148 != 0) {
            if (*(char **)(local_148 + 8) == (char *)0x0) {
              lVar8 = 0;
            }
            else {
              lVar8 = _strtol(*(char **)(local_148 + 8),(char **)0x0,10);
            }
          }
          iVar9 = local_14c + 0xbd7c;
          local_134 = lVar7;
          local_130 = lVar8;
          uVar6 = FUN_0057ef20();
          FUN_0057e850(iVar9,uVar6);
          pppiVar3 = (int ***)local_124;
        }
        local_150 = local_150 + 2;
      } while (local_150 != local_120);
    }
    if (pppiVar3 != (int ***)0x0) {
      FUN_0089120c(pppiVar3);
    }
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c);
    }
  }
  local_28 = 0xf;
  local_2c = 0;
  local_3c = local_3c & 0xffffff00;
  FUN_0071bc90(&local_108);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_154);
  return;
}

