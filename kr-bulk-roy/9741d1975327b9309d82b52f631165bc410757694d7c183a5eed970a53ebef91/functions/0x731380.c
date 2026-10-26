
char * FUN_00731380(char *param_1,char *param_2,undefined4 *param_3,int param_4)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  undefined **ppuVar8;
  int local_8;
  
  *param_3 = 0;
  cVar7 = param_1[1];
  if ((cVar7 != '\0') && (cVar7 == '#')) {
    if (param_1[2] != '\0') {
      cVar5 = '\0';
      cVar7 = '\x01';
      if (param_1[2] == 'x') {
        if (((param_1[3] != '\0') && (pcVar2 = _strchr(param_1 + 3,0x3b), pcVar2 != (char *)0x0)) &&
           (*pcVar2 != '\0')) {
          local_8 = (int)pcVar2 - (int)param_1;
          pcVar2 = pcVar2 + -1;
          cVar4 = *pcVar2;
          while (cVar4 != 'x') {
            if ((cVar4 < '0') || ('9' < cVar4)) {
              if ((cVar4 < 'a') || ('f' < cVar4)) {
                if (cVar4 < 'A') {
                  return (char *)0x0;
                }
                if ('F' < cVar4) {
                  return (char *)0x0;
                }
                cVar4 = cVar4 + -0x37;
              }
              else {
                cVar4 = cVar4 + -0x57;
              }
            }
            else {
              cVar4 = cVar4 + -0x30;
            }
            cVar5 = cVar5 + cVar4 * cVar7;
            pcVar1 = pcVar2 + -1;
            pcVar2 = pcVar2 + -1;
            cVar7 = cVar7 << 4;
            cVar4 = *pcVar1;
          }
LAB_007314a2:
          if (param_4 == 1) {
            FUN_00730e70(param_2);
            return param_1 + local_8 + 1;
          }
          *param_2 = cVar5;
          *param_3 = 1;
          return param_1 + local_8 + 1;
        }
      }
      else {
        pcVar2 = _strchr(param_1 + 2,0x3b);
        if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
          local_8 = (int)pcVar2 - (int)param_1;
          pcVar2 = pcVar2 + -1;
          cVar4 = *pcVar2;
          while (cVar4 != '#') {
            if (cVar4 < '0') {
              return (char *)0x0;
            }
            if ('9' < cVar4) {
              return (char *)0x0;
            }
            pcVar1 = pcVar2 + -1;
            pcVar2 = pcVar2 + -1;
            cVar5 = cVar5 + (cVar4 + -0x30) * cVar7;
            cVar7 = cVar7 * '\n';
            cVar4 = *pcVar1;
          }
          goto LAB_007314a2;
        }
      }
      return (char *)0x0;
    }
  }
  iVar6 = 0;
  ppuVar8 = &PTR_s__amp__00d63ccc;
  do {
    iVar3 = _strncmp(*ppuVar8,param_1,(size_t)ppuVar8[1]);
    if (iVar3 == 0) {
      *param_2 = (&DAT_00d63cd4)[iVar6 * 0xc];
      iVar6 = (&DAT_00d63cd0)[iVar6 * 3];
      *param_3 = 1;
      return param_1 + iVar6;
    }
    ppuVar8 = ppuVar8 + 3;
    iVar6 = iVar6 + 1;
  } while ((int)ppuVar8 < 0xd63d08);
  *param_2 = *param_1;
  return param_1 + 1;
}

