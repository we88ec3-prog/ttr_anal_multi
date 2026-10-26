
/* WARNING: Type propagation algorithm not settling */

void FUN_0066e940(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  undefined2 *in_ECX;
  undefined4 *puVar7;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  short *local_128;
  short *local_124;
  uint local_120 [2];
  short local_118;
  undefined1 local_116 [254];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c022;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_134 = 0;
  local_12c = 0;
  local_148 = 0;
  local_138 = 0;
  local_140 = 0;
  local_144 = 0x34;
  local_130 = 1;
  local_13c = 1;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_18 = 0;
  local_124 = (short *)&DAT_00c34dac;
  psVar4 = &local_118;
  local_120[0] = 0;
  local_128 = (short *)0x0;
  sVar1 = 0x7b;
  do {
    psVar6 = local_124;
    if (sVar1 == 0x7b) {
      if (local_124[1] != 0x7b) {
        local_120[0] = 1;
        local_128 = local_124;
        goto LAB_0066ed83;
      }
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 == 0x100) {
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
        psVar4 = &local_118;
      }
      *psVar4 = 0x7b;
      psVar4 = psVar4 + 1;
      local_124 = psVar6 + 2;
      goto LAB_0066edfe;
    }
    if (sVar1 != 0x7d) {
      if (local_120[0] == 0) {
        *psVar4 = sVar1;
        psVar4 = psVar4 + 1;
      }
LAB_0066ed83:
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 == 0x100) {
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
LAB_0066ed3b:
        FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
        psVar4 = &local_118;
      }
LAB_0066ed54:
      local_124 = psVar6 + 1;
      goto LAB_0066edfe;
    }
    if (local_120[0] == 0) {
      *psVar4 = 0x7d;
      psVar4 = psVar4 + 1;
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 == 0x100) {
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        goto LAB_0066ed3b;
      }
      goto LAB_0066ed54;
    }
    local_120[1] = 0;
    local_120[0] = 0xffffffff;
    iVar3 = FUN_00403e00(local_120,local_120 + 1,local_124,uVar2);
    if ((3 < local_120[0]) || (8 < (int)local_120[0])) goto switchD_0066eaaf_default;
    *psVar4 = 0;
    psVar4 = &local_118;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
    psVar4 = &local_118;
    if (iVar3 != 0) {
      switch(local_120[0]) {
      case 0:
        FUN_00403fd0(in_ECX);
        break;
      case 1:
        FUN_00403fd0(in_ECX);
        break;
      case 2:
        FUN_00403fd0(in_ECX);
        break;
      case 3:
        FUN_00453c40(in_ECX);
        break;
      case 4:
        FUN_00403fd0(in_ECX);
        break;
      case 5:
        FUN_00403fd0(in_ECX);
        break;
      case 6:
        FUN_00403fd0(in_ECX);
        break;
      case 7:
        FUN_00403fd0(in_ECX);
        break;
      case 8:
        FUN_00403fd0(in_ECX);
      }
      goto switchD_0066eaaf_default;
    }
    switch(local_120[0]) {
    case 0:
      puVar7 = &local_13c;
      break;
    case 1:
      puVar7 = &local_130;
      break;
    case 2:
      puVar7 = &local_144;
      break;
    case 3:
      FUN_00453be0(&stack0x00000004);
      goto switchD_0066eaaf_default;
    case 4:
      puVar7 = &local_140;
      break;
    case 5:
      puVar7 = &local_138;
      break;
    case 6:
      puVar7 = &local_148;
      break;
    case 7:
      puVar7 = &local_12c;
      break;
    case 8:
      puVar7 = &local_134;
      break;
    default:
      goto switchD_0066eaaf_default;
    }
    FUN_00404190(puVar7);
switchD_0066eaaf_default:
    local_124 = local_124 + 1;
    local_120[0] = 0;
LAB_0066edfe:
    sVar1 = *local_124;
    if (sVar1 == 0) {
      psVar6 = &local_118;
      if (psVar4 != psVar6) {
        *psVar4 = 0;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar6 - (int)local_116 >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

