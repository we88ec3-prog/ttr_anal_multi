
void FUN_006cdb80(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  wchar_t *****pppppwVar5;
  wchar_t *pwVar6;
  short *psVar7;
  undefined *puVar8;
  wchar_t *pwVar9;
  wchar_t ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912306;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00fba80c == 0) {
    iVar2 = FUN_00891268(0x57c,local_14);
    if (iVar2 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  piVar3 = (int *)FUN_006f1640(DAT_00fba80c);
  if ((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 0x30))(), iVar2 != 0)) {
    psVar4 = (short *)(**(code **)(*piVar3 + 0xc))();
    local_30[0] = (wchar_t ****)((uint)local_30[0] & 0xffff0000);
    local_1c = 7;
    local_20 = 0;
    psVar7 = psVar4;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar7 - (int)(psVar4 + 1) >> 1);
    local_8 = 0;
    puVar8 = &DAT_00f74378;
    do {
      pppppwVar5 = (wchar_t *****)local_30[0];
      if (local_1c < 8) {
        pppppwVar5 = local_30;
      }
      iVar2 = FUN_0044df20(0,pppppwVar5,local_20);
      if (iVar2 == 0) {
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        goto LAB_006cddcf;
      }
      puVar8 = puVar8 + 0x54;
    } while ((int)puVar8 < 0xf744c8);
    pwVar9 = (wchar_t *)&DAT_00f74394;
    do {
      pwVar6 = pwVar9;
      if (7 < *(uint *)(pwVar9 + 10)) {
        pwVar6 = *(wchar_t **)pwVar9;
      }
      pppppwVar5 = (wchar_t *****)local_30[0];
      if (local_1c < 8) {
        pppppwVar5 = local_30;
      }
      pwVar6 = _wcsstr((wchar_t *)pppppwVar5,pwVar6);
      if (pwVar6 != (wchar_t *)0x0) {
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        goto LAB_006cddcf;
      }
      pwVar9 = pwVar9 + 0x2a;
    } while ((int)pwVar9 < 0xf744e4);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    switch(DAT_00fb90d1) {
    case 1:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      break;
    case 2:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      break;
    case 3:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      break;
    case 4:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      break;
    default:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      break;
    case 7:
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
LAB_006cddcf:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

