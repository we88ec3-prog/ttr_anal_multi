
void FUN_00704e10(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined2 in_FPUControlWord;
  float10 fVar9;
  undefined1 auStack_4b4 [40];
  int local_48c;
  int local_488;
  int local_484;
  longlong local_480;
  uint local_478;
  char *local_474;
  char *local_470;
  int local_46c;
  int local_468;
  char local_464 [512];
  char local_264 [8];
  char local_25c [20];
  char local_248 [516];
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)auStack_4b4;
  iVar8 = 1;
  local_484 = param_1;
  local_488 = 1;
  pcVar4 = (char *)FUN_006f6210();
  local_474 = pcVar4 + local_48c;
  local_470 = local_464;
  local_468 = param_1;
  local_46c = 0;
  if (pcVar4 < local_474) {
    do {
      iVar3 = local_468;
      if ((*pcVar4 != '%') || (pcVar4 = pcVar4 + 1, *pcVar4 == '%')) {
        if ((local_264 <= local_470) &&
           (local_48c = (int)local_470 - (int)local_464, local_48c != 0)) {
          if (*(uint *)(*(int *)(local_468 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(local_468 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          puVar2 = *(undefined4 **)(iVar3 + 8);
          uVar5 = FUN_006fec70(iVar3,local_464);
          *puVar2 = uVar5;
          puVar2[2] = 4;
          *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x10;
          local_46c = local_46c + 1;
          local_470 = local_464;
          FUN_006f6b60();
          iVar8 = local_488;
          param_1 = local_484;
        }
        *local_470 = *pcVar4;
        local_470 = local_470 + 1;
        pcVar4 = pcVar4 + 1;
        goto LAB_00705142;
      }
      iVar8 = iVar8 + 1;
      local_488 = iVar8;
      pcVar6 = (char *)FUN_00704d30(pcVar4);
      pcVar4 = pcVar6 + 1;
      switch(*pcVar6) {
      case 'E':
      case 'G':
      case 'e':
      case 'f':
      case 'g':
        fVar9 = (float10)FUN_006f6290(param_1,iVar8);
        _sprintf(local_248,local_25c,(double)fVar9);
        break;
      default:
        FUN_006f5f30(param_1,"invalid option \'%%%c\' to \'format\'",(int)*pcVar6);
        __security_check_cookie(local_44 ^ (uint)auStack_4b4);
        return;
      case 'X':
      case 'o':
      case 'u':
      case 'x':
        pcVar7 = local_25c;
        pcVar6 = local_25c + 1;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        cVar1 = pcVar7[(int)(local_264 + (7 - (int)pcVar6))];
        (pcVar7 + (int)(local_264 + (7 - (int)pcVar6)))[0] = 'l';
        (pcVar7 + (int)(local_264 + (7 - (int)pcVar6)))[1] = '\0';
        pcVar7[(int)(local_25c + -(int)pcVar6)] = cVar1;
        pcVar7[(int)(local_25c + (1 - (int)pcVar6))] = '\0';
        fVar9 = (float10)FUN_006f6290(CONCAT44(iVar8,param_1));
        local_48c = CONCAT22(local_48c._2_2_,in_FPUControlWord);
        local_480 = (longlong)ROUND(fVar9);
        _sprintf(local_248,local_25c,(undefined4)local_480);
        break;
      case 'c':
        FUN_006f6290(param_1);
        uVar5 = FUN_008fed10();
        _sprintf(local_248,local_25c,uVar5);
        break;
      case 'd':
      case 'i':
        pcVar7 = local_25c;
        pcVar6 = local_25c + 1;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        cVar1 = pcVar7[(int)(local_264 + (7 - (int)pcVar6))];
        (pcVar7 + (int)(local_264 + (7 - (int)pcVar6)))[0] = 'l';
        (pcVar7 + (int)(local_264 + (7 - (int)pcVar6)))[1] = '\0';
        pcVar7[(int)(local_25c + -(int)pcVar6)] = cVar1;
        pcVar7[(int)(local_25c + (1 - (int)pcVar6))] = '\0';
        FUN_006f6290(CONCAT44(iVar8,param_1));
        uVar5 = FUN_008fed10();
        _sprintf(local_248,local_25c,uVar5);
        break;
      case 'q':
        FUN_00704b40();
        goto LAB_00705142;
      case 's':
        uVar5 = FUN_006f6210();
        local_480 = CONCAT44(local_480._4_4_,uVar5);
        pcVar6 = _strchr(local_25c,0x2e);
        if ((pcVar6 != (char *)0x0) || (local_478 < 100)) {
          _sprintf(local_248,local_25c);
          break;
        }
        FUN_006f5300();
        FUN_006f6cd0();
        iVar8 = local_488;
        goto LAB_00705142;
      }
      pcVar6 = local_248;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_006f6c40(local_248);
      iVar8 = local_488;
LAB_00705142:
    } while (pcVar4 < local_474);
  }
  FUN_006f6af0();
  FUN_006f5bb0();
  __security_check_cookie(local_44 ^ (uint)auStack_4b4);
  return;
}

