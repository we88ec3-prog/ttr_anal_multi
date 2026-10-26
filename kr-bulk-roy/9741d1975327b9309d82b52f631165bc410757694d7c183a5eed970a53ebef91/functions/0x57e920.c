
void FUN_0057e920(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *in_ECX;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 local_c0;
  undefined4 local_bc;
  char *local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  char *local_a4;
  uint local_a0;
  undefined4 local_9c;
  char local_98 [128];
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091dc32;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_b0 = 0;
  local_ac = 0;
  local_b4 = 0;
  local_a8 = 0;
  local_c0 = 0;
  local_bc = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *in_ECX = 0;
  local_8 = 0;
  cVar1 = *param_1;
  local_18 = 0;
  pcVar5 = local_98;
  local_a0 = 0;
  local_b8 = (char *)0x0;
  do {
    local_a4 = param_1;
    if (cVar1 == '\0') {
      pcVar4 = local_98;
      if (pcVar5 != pcVar4) {
        *pcVar5 = '\0';
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (cVar1 == '{') {
      if (param_1[1] == '{') {
        pcVar4 = local_98;
        if ((int)pcVar5 - (int)pcVar4 == 0x80) {
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
          pcVar5 = local_98;
        }
        *pcVar5 = '{';
        pcVar5 = pcVar5 + 1;
        local_a4 = param_1 + 2;
        goto LAB_0057ee7d;
      }
      local_a0 = 1;
      local_b8 = param_1;
LAB_0057edfa:
      pcVar4 = local_98;
      if ((int)pcVar5 - (int)pcVar4 == 0x80) {
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
        pcVar5 = local_98;
        local_a4 = param_1 + 1;
      }
      else {
LAB_0057edd1:
        local_a4 = param_1 + 1;
      }
    }
    else {
      if (cVar1 != '}') {
        if (local_a0 == 0) {
          *pcVar5 = cVar1;
          pcVar5 = pcVar5 + 1;
        }
        goto LAB_0057edfa;
      }
      if (local_a0 == 0) {
        *pcVar5 = '}';
        pcVar5 = pcVar5 + 1;
        pcVar4 = local_98;
        if ((int)pcVar5 - (int)pcVar4 == 0x80) {
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
          pcVar5 = local_98;
        }
        goto LAB_0057edd1;
      }
      local_9c = 0;
      local_a0 = 0xffffffff;
      iVar3 = FUN_004ad850(&local_a0,&local_9c,param_1,uVar2);
      if ((local_a0 < 3) && ((int)local_a0 < 9)) {
        pcVar4 = local_98;
        *pcVar5 = '\0';
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
        pcVar5 = local_98;
        if (iVar3 == 0) {
          switch(local_a0) {
          case 0:
            puVar6 = (undefined4 *)&stack0x00000008;
            break;
          case 1:
            puVar6 = (undefined4 *)&stack0x0000000c;
            break;
          case 2:
            puVar6 = (undefined4 *)&stack0x00000010;
            break;
          case 3:
            puVar6 = &local_bc;
            break;
          case 4:
            puVar6 = &local_c0;
            break;
          case 5:
            puVar6 = &local_a8;
            break;
          case 6:
            puVar6 = &local_b4;
            break;
          case 7:
            puVar6 = &local_ac;
            break;
          case 8:
            puVar6 = &local_b0;
            break;
          default:
            goto switchD_0057ea79_default;
          }
          FUN_004ad910(puVar6);
          goto switchD_0057ea79_default;
        }
        switch(local_a0) {
        case 0:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 1:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 2:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 3:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 4:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 5:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 6:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 7:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        case 8:
          FUN_004ad970(in_ECX);
          local_a4 = local_a4 + 1;
          local_a0 = 0;
          break;
        default:
          goto switchD_0057ea79_default;
        }
      }
      else {
switchD_0057ea79_default:
        local_a4 = local_a4 + 1;
        local_a0 = 0;
      }
    }
LAB_0057ee7d:
    cVar1 = *local_a4;
    param_1 = local_a4;
  } while( true );
}

