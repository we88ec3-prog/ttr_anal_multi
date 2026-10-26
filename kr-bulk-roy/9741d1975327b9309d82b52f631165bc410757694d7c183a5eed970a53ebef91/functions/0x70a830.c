
undefined4 FUN_0070a830(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_20;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  pcVar3 = (char *)FUN_006f6210(param_1);
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U);
  }
  iVar8 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x10;
  local_18[0] = FUN_006fec70(param_1,"_LOADED",7);
  local_10 = 4;
  FUN_006fb850(param_1,iVar8 + 0x60,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  puVar9 = &DAT_00c0bfc8;
  if (puVar4 < *(undefined4 **)(param_1 + 8)) {
    puVar9 = puVar4;
  }
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
  local_10 = 4;
  FUN_006fb850(param_1,puVar9,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar8 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar8 + -8);
  if ((iVar2 != 0) && ((iVar2 != 1 || (*(int *)(iVar8 + -0x10) != 0)))) {
    if (iVar2 == 2) {
      puVar6 = *(undefined **)(iVar8 + -0x10);
    }
    else if (iVar2 == 7) {
      puVar6 = (undefined *)(*(int *)(iVar8 + -0x10) + 0x18);
    }
    else {
      puVar6 = (undefined *)0x0;
    }
    if (puVar6 != &DAT_00c08b14) {
      return 1;
    }
    FUN_006f5f30(param_1,"loop or previous error loading module \'%s\'",pcVar3);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  *(undefined4 *)(param_1 + 0x60) = 5;
  local_18[0] = FUN_006fec70(param_1,"loaders",7);
  local_10 = 4;
  FUN_006fb850(param_1,(undefined4 *)(param_1 + 0x58),local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if ((*(undefined **)(param_1 + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(param_1 + 8) + -8) != 5)) {
    FUN_006f5f30(param_1,"\'package.loaders\' must be a table");
  }
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar9 = *(undefined4 **)(param_1 + 8);
  uVar7 = FUN_006fec70(param_1,&DAT_00bf2375,0);
  *puVar9 = uVar7;
  puVar9[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  local_20 = 1;
LAB_0070aa05:
  do {
    puVar9 = *(undefined4 **)(param_1 + 8);
    puVar4 = (undefined4 *)FUN_006f9b70(local_20);
    *puVar9 = *puVar4;
    puVar9[1] = puVar4[1];
    puVar9[2] = puVar4[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar6 = *(undefined **)(param_1 + 8);
    if ((puVar6 != &DAT_00c0bfd8) && (*(int *)(puVar6 + -8) == 0)) {
      if (*(int *)(puVar6 + -0x18) == 4) {
LAB_0070aa6d:
        iVar8 = *(int *)(puVar6 + -0x20) + 0x10;
      }
      else {
        iVar8 = FUN_006fb5d0();
        if (iVar8 != 0) {
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          puVar6 = *(undefined **)(param_1 + 8);
          goto LAB_0070aa6d;
        }
        iVar8 = 0;
      }
      FUN_006f5f30(param_1,"module \'%s\' not found:%s",pcVar3,iVar8);
    }
    if (pcVar3 == (char *)0x0) {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    }
    else {
      pcVar5 = pcVar3;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      puVar9 = *(undefined4 **)(param_1 + 8);
      uVar7 = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
      *puVar9 = uVar7;
      puVar9[2] = 4;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x20,1);
    iVar8 = *(int *)(param_1 + 8);
    puVar9 = (undefined4 *)(iVar8 + -0x10);
    if (puVar9 != &DAT_00c0bfc8) {
      if (*(int *)(iVar8 + -8) == 6) {
        puVar9 = *(undefined4 **)(param_1 + 8);
        *puVar9 = &DAT_00c08b14;
        puVar9[2] = 2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
        puVar9 = &DAT_00c0bfc8;
        if (puVar4 < *(undefined4 **)(param_1 + 8)) {
          puVar9 = puVar4;
        }
        pcVar5 = pcVar3;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
        local_10 = 4;
        FUN_006fb9a0(param_1,puVar9,local_18,*(int *)(param_1 + 8) + -0x10);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        if (pcVar3 == (char *)0x0) {
          *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
        }
        else {
          pcVar5 = pcVar3;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          puVar9 = *(undefined4 **)(param_1 + 8);
          uVar7 = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
          *puVar9 = uVar7;
          puVar9[2] = 4;
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x20,1);
        puVar9 = *(undefined4 **)(param_1 + 8);
        if ((puVar9 == (undefined4 *)&DAT_00c0bfd8) || (puVar9[-2] != 0)) {
          puVar10 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
          puVar4 = &DAT_00c0bfc8;
          if (puVar10 < puVar9) {
            puVar4 = puVar10;
          }
          pcVar5 = pcVar3;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
          local_10 = 4;
          FUN_006fb9a0(param_1,puVar4,local_18,*(int *)(param_1 + 8) + -0x10);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        }
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
        puVar9 = &DAT_00c0bfc8;
        if (puVar4 < *(undefined4 **)(param_1 + 8)) {
          puVar9 = puVar4;
        }
        pcVar5 = pcVar3;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
        local_10 = 4;
        FUN_006fb850(param_1,puVar9,local_18,*(undefined4 *)(param_1 + 8));
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        puVar9 = *(undefined4 **)(param_1 + 8);
        if (puVar9[-2] == 2) {
          puVar6 = (undefined *)puVar9[-4];
        }
        else if (puVar9[-2] == 7) {
          puVar6 = (undefined *)(puVar9[-4] + 0x18);
        }
        else {
          puVar6 = (undefined *)0x0;
        }
        if (puVar6 != &DAT_00c08b14) {
          return 1;
        }
        *puVar9 = 1;
        puVar9[2] = 1;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        puVar9 = *(undefined4 **)(param_1 + 8);
        *puVar9 = puVar9[-4];
        puVar9[1] = puVar9[-3];
        puVar9[2] = puVar9[-2];
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
        puVar9 = &DAT_00c0bfc8;
        if (puVar4 < *(undefined4 **)(param_1 + 8)) {
          puVar9 = puVar4;
        }
        pcVar5 = pcVar3;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar5 - (int)(pcVar3 + 1));
        local_10 = 4;
        FUN_006fb9a0(param_1,puVar9,local_18,*(int *)(param_1 + 8) + -0x10);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        return 1;
      }
      if ((puVar9 != &DAT_00c0bfc8) && ((*(int *)(iVar8 + -8) == 4 || (*(int *)(iVar8 + -8) == 3))))
      {
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        FUN_006fc080(param_1,2,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        local_20 = local_20 + 1;
        goto LAB_0070aa05;
      }
    }
    local_20 = local_20 + 1;
    *(undefined4 **)(param_1 + 8) = puVar9;
  } while( true );
}

