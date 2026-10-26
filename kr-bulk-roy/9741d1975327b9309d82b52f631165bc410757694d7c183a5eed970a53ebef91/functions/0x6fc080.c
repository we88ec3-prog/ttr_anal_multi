
void FUN_006fc080(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  size_t _Size;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined1 auStack_b4 [56];
  int local_7c;
  int *local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  char local_64 [32];
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)auStack_b4;
  local_7c = param_1;
  do {
    iVar7 = (param_3 + 1) * 0x10 + *(int *)(param_1 + 0xc);
    local_74 = 2;
    local_6c = param_3;
    if ((*(int *)(iVar7 + -0x18) == 4) || (*(int *)(iVar7 + -0x18) == 3)) {
      if (*(int *)(iVar7 + -8) != 4) {
        if (*(int *)(iVar7 + -8) != 3) goto LAB_006fc184;
        _sprintf(local_64,"%.14g",*(undefined8 *)(iVar7 + -0x10));
        pcVar3 = local_64;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        uVar4 = FUN_006fec70(param_1,local_64);
        *(undefined4 *)(iVar7 + -0x10) = uVar4;
        *(undefined4 *)(iVar7 + -8) = 4;
      }
      piVar6 = *(int **)(*(int *)(iVar7 + -0x10) + 0xc);
      if (piVar6 == (int *)0x0) {
        if ((*(int *)(iVar7 + -0x18) != 4) && (*(int *)(iVar7 + -0x18) == 3)) {
          _sprintf(local_64,"%.14g",*(undefined8 *)(iVar7 + -0x20));
          pcVar3 = local_64;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uVar4 = FUN_006fec70(param_1,local_64);
          *(undefined4 *)(iVar7 + -0x20) = uVar4;
          *(undefined4 *)(iVar7 + -0x18) = 4;
        }
      }
      else {
        local_74 = 1;
        local_78 = piVar6;
        if (1 < param_2) {
          piVar9 = (int *)(iVar7 + -0x20);
          do {
            local_78 = piVar6;
            if (piVar9[2] != 4) {
              if (piVar9[2] != 3) break;
              _sprintf(local_64,"%.14g",*(undefined8 *)piVar9);
              pcVar3 = local_64;
              do {
                cVar1 = *pcVar3;
                pcVar3 = pcVar3 + 1;
              } while (cVar1 != '\0');
              iVar5 = FUN_006fec70(local_7c,local_64);
              *piVar9 = iVar5;
              piVar9[2] = 4;
            }
            uVar2 = *(uint *)(*piVar9 + 0xc);
            if (-(int)local_78 - 3U <= uVar2) {
              FUN_006f8b60(local_7c);
            }
            local_74 = local_74 + 1;
            piVar6 = (int *)((int)local_78 + uVar2);
            piVar9 = piVar9 + -4;
            local_78 = piVar6;
          } while (local_74 < param_2);
        }
        iVar5 = *(int *)(local_7c + 0x10);
        if (*(int **)(iVar5 + 0x3c) < local_78) {
          piVar6 = local_78;
          if (local_78 < (int *)0x20) {
            piVar6 = (int *)0x20;
          }
          if ((int)piVar6 + 1U < 0xfffffffe) {
            uVar4 = FUN_00700880(local_7c,*(undefined4 *)(iVar5 + 0x34),*(int **)(iVar5 + 0x3c));
          }
          else {
            FUN_006f8b60(local_7c);
            uVar4 = 0;
          }
          *(undefined4 *)(iVar5 + 0x34) = uVar4;
          *(int **)(iVar5 + 0x3c) = piVar6;
        }
        local_68 = *(int *)(iVar5 + 0x34);
        iVar5 = 0;
        local_70 = local_74;
        if (0 < local_74) {
          local_78 = (int *)(iVar7 + local_74 * -0x10);
          do {
            _Size = *(size_t *)(*local_78 + 0xc);
            FID_conflict__memcpy((void *)(local_68 + iVar5),(void *)(*local_78 + 0x10),_Size);
            local_78 = local_78 + 4;
            local_70 = local_70 + -1;
            iVar5 = iVar5 + _Size;
          } while (0 < local_70);
        }
        puVar8 = (undefined4 *)(iVar7 + local_74 * -0x10);
        uVar4 = FUN_006fec70(local_7c,local_68);
        *puVar8 = uVar4;
        puVar8[2] = 4;
        param_1 = local_7c;
      }
    }
    else {
LAB_006fc184:
      iVar7 = FUN_006fbb80(param_1,iVar7 + -0x20,iVar7 + -0x10,iVar7 + -0x20);
      if (iVar7 == 0) {
        FUN_006f8970();
        param_1 = local_7c;
      }
    }
    param_2 = param_2 + (1 - local_74);
    param_3 = local_6c + (1 - local_74);
    if (param_2 < 2) {
      local_6c = param_3;
      __security_check_cookie(local_44 ^ (uint)auStack_b4);
      return;
    }
  } while( true );
}

