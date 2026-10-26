
void FUN_00701a50(int param_1)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int local_74;
  int local_70;
  undefined4 local_68;
  char *local_64;
  char *local_60;
  int local_58;
  undefined4 local_50;
  undefined1 local_48 [64];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar3 = *(int **)(param_1 + 0xc);
  iVar8 = 1;
  bVar2 = true;
  if (((piVar3 < *(int **)(param_1 + 8)) && (piVar3 != &DAT_00c0bfc8)) && (piVar3[2] == 8)) {
    local_74 = 1;
    if (*(int **)(param_1 + 8) <= piVar3) {
      piVar3 = &DAT_00c0bfc8;
    }
    if (piVar3[2] == 8) {
      local_70 = *piVar3;
    }
    else {
      local_70 = 0;
    }
  }
  else {
    local_74 = 0;
    iVar8 = 0;
    local_70 = param_1;
  }
  iVar4 = FUN_006f50f0();
  if ((*(int *)(iVar4 + 8) == 3) ||
     ((*(int *)(iVar4 + 8) == 4 && (iVar4 = FUN_006f7760(), iVar8 = local_74, iVar4 != 0)))) {
    uVar5 = FUN_006f5370();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  }
  else {
    uVar5 = (uint)(param_1 == local_70);
  }
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4 == iVar8) {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    uVar10 = 0;
    puVar9 = &DAT_00bf2375;
  }
  else {
    puVar6 = (undefined4 *)FUN_006f50f0();
    if ((puVar6 == &DAT_00c0bfc8) || ((puVar6[2] != 4 && (puVar6[2] != 3)))) goto LAB_00701de1;
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    uVar10 = 1;
    puVar9 = &DAT_00c411c0;
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  uVar10 = FUN_006fec70(param_1,puVar9,uVar10);
  *puVar6 = uVar10;
  puVar6[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  uVar10 = FUN_006fec70(param_1,"stack traceback:",0x10);
  *puVar6 = uVar10;
  puVar6[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar8 = FUN_006f7dd0();
  while (iVar8 != 0) {
    uVar7 = uVar5 + 1;
    if (((int)uVar7 < 0xd) || (!bVar2)) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      uVar10 = FUN_006fec70(param_1,&DAT_00c43030,2);
      *puVar6 = uVar10;
      puVar6[2] = 4;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f8180(&DAT_00c43034);
      FUN_006f5580(param_1,&DAT_00c43038,local_48);
      if (0 < local_58) {
        FUN_006f5580(param_1,&DAT_00c4303c,local_58);
      }
      if (*local_64 == '\0') {
        cVar1 = *local_60;
        if (cVar1 == 'm') {
          FUN_006f5580(param_1," in main chunk");
        }
        else if ((cVar1 == 'C') || (cVar1 == 't')) {
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          puVar6 = *(undefined4 **)(param_1 + 8);
          uVar10 = FUN_006fec70(param_1,&DAT_00c43064,2);
          *puVar6 = uVar10;
          puVar6[2] = 4;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        }
        else {
          FUN_006f5580(param_1," in function <%s:%d>",local_48,local_50);
        }
      }
      else {
        FUN_006f5580(param_1," in function \'%s\'",local_68);
      }
      puVar6 = *(undefined4 **)(param_1 + 8);
      iVar8 = ((int)puVar6 - *(int *)(param_1 + 0xc) >> 4) - local_74;
      if (iVar8 < 2) {
        if (iVar8 == 0) {
          uVar10 = FUN_006fec70(param_1,&DAT_00bf2375,0);
          *puVar6 = uVar10;
          puVar6[2] = 4;
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        }
      }
      else {
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        FUN_006fc080(param_1,iVar8,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar8 * -0x10 + 0x10;
      }
    }
    else {
      iVar8 = FUN_006f7dd0();
      if (iVar8 == 0) {
        bVar2 = false;
        uVar7 = uVar5;
      }
      else {
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        puVar6 = *(undefined4 **)(param_1 + 8);
        uVar10 = FUN_006fec70(param_1,"\n\t...",5);
        *puVar6 = uVar10;
        puVar6[2] = 4;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        iVar8 = FUN_006f7dd0();
        while (iVar8 != 0) {
          uVar7 = uVar7 + 1;
          iVar8 = FUN_006f7dd0();
        }
        bVar2 = false;
      }
    }
    iVar8 = FUN_006f7dd0();
    uVar5 = uVar7;
  }
  FUN_006f5bb0();
LAB_00701de1:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

