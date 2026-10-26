
/* WARNING: Type propagation algorithm not settling */

void FUN_0053d010(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  undefined2 *in_ECX;
  undefined4 *puVar7;
  undefined4 local_140;
  undefined4 local_13c;
  short *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  short *local_124;
  uint local_120 [2];
  short local_118;
  undefined1 local_116 [254];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091be12;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_13c = param_1;
  local_130 = 0;
  local_12c = 0;
  local_134 = 0;
  local_128 = 0;
  local_140 = 0;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_18 = 0;
  local_124 = (short *)&DAT_00c0f334;
  psVar4 = &local_118;
  local_120[0] = 0;
  local_138 = (short *)0x0;
  sVar1 = 0x7b;
  do {
    psVar6 = local_124;
    if (sVar1 == 0x7b) {
      if (local_124[1] != 0x7b) {
        local_120[0] = 1;
        local_138 = local_124;
        goto LAB_0053d443;
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
      goto LAB_0053d4da;
    }
    if (sVar1 != 0x7d) {
      if (local_120[0] == 0) {
        *psVar4 = sVar1;
        psVar4 = psVar4 + 1;
      }
LAB_0053d443:
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 != 0x100) goto LAB_0053d414;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
      psVar4 = &local_118;
      local_124 = psVar6 + 1;
      goto LAB_0053d4da;
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
        FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
        psVar4 = &local_118;
      }
LAB_0053d414:
      local_124 = psVar6 + 1;
      goto LAB_0053d4da;
    }
    local_120[1] = 0;
    local_120[0] = 0xffffffff;
    iVar3 = FUN_00403e00(local_120,local_120 + 1,local_124,uVar2);
    if ((3 < local_120[0]) || (8 < (int)local_120[0])) goto switchD_0053d16f_default;
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
        FUN_00479d80(in_ECX);
        break;
      case 1:
        FUN_00403fd0(in_ECX);
        break;
      case 2:
        FUN_00427610(in_ECX);
        break;
      case 3:
        FUN_00427610(in_ECX);
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
      goto switchD_0053d16f_default;
    }
    switch(local_120[0]) {
    case 0:
      FUN_00479e90();
      goto switchD_0053d16f_default;
    case 1:
      puVar7 = (undefined4 *)&stack0x00000008;
      break;
    case 2:
      FUN_004275b0(&stack0x0000000c);
      goto switchD_0053d16f_default;
    case 3:
      FUN_004275b0(&stack0x00000010);
      goto switchD_0053d16f_default;
    case 4:
      puVar7 = &local_140;
      break;
    case 5:
      puVar7 = &local_128;
      break;
    case 6:
      puVar7 = &local_134;
      break;
    case 7:
      puVar7 = &local_12c;
      break;
    case 8:
      puVar7 = &local_130;
      break;
    default:
      goto switchD_0053d16f_default;
    }
    FUN_00404190(puVar7);
switchD_0053d16f_default:
    local_124 = local_124 + 1;
    local_120[0] = 0;
LAB_0053d4da:
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

