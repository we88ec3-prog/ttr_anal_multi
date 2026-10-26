
char * FUN_0071ade0(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  char *pcVar7;
  
  pcVar7 = (char *)(in_EAX + 1);
  cVar2 = *pcVar7;
  if (cVar2 == '-') {
    pcVar7 = (char *)(in_EAX + 2);
    if (*pcVar7 == '-') {
      pcVar7 = (char *)(in_EAX + 3);
      uVar5 = param_3 & 2;
      if (uVar5 != 0) {
        param_2 = FUN_0071a530(param_1);
        if (param_2 == 0) {
          *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
          FID_conflict____longjmp_internal((int *)(param_1 + 0xc),3);
        }
        *(char **)(param_2 + 0xc) = pcVar7;
      }
      if (((param_3 & 0x20) != 0) && (uVar5 != 0)) {
        pcVar7 = (char *)FUN_0071aaa0(param_4);
        if (pcVar7 != (char *)0x0) {
          return pcVar7;
        }
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0xc);
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),7);
      }
      if (*pcVar7 != '\0') {
        do {
          if (((*pcVar7 == '-') && (pcVar7[1] == '-')) &&
             ((pcVar7[2] == '>' || ((pcVar7[2] == '\0' && ((char)param_4 == '>')))))) break;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar7 != '\0');
        if (*pcVar7 != '\0') {
          if (uVar5 != 0) {
            *pcVar7 = '\0';
          }
          return pcVar7 + (pcVar7[2] == '>') + 2;
        }
      }
    }
    *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
    FID_conflict____longjmp_internal((int *)(param_1 + 0xc),7);
  }
  if (cVar2 != '[') {
    if (((((cVar2 == 'D') && (*(char *)(in_EAX + 2) == 'O')) && (*(char *)(in_EAX + 3) == 'C')) &&
        ((*(char *)(in_EAX + 4) == 'T' && (*(char *)(in_EAX + 5) == 'Y')))) &&
       ((*(char *)(in_EAX + 6) == 'P' &&
        ((*(char *)(in_EAX + 7) == 'E' ||
         ((*(char *)(in_EAX + 7) == '\0' && ((char)param_4 == 'E')))))))) {
      if (*(int *)(param_2 + 4) != 0) {
        *(int *)(param_1 + 8) = in_EAX + -1;
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),9);
      }
      pbVar6 = (byte *)(in_EAX + 8);
      pcVar7 = (char *)FUN_0071ad60(in_EAX + -1,param_4,1);
      if ((param_3 & 0x200) != 0) {
        bVar3 = (&DAT_00c0b650)[*pbVar6];
        while ((bVar3 & 8) != 0) {
          pbVar1 = pbVar6 + 1;
          pbVar6 = pbVar6 + 1;
          bVar3 = (&DAT_00c0b650)[*pbVar1];
        }
        iVar4 = FUN_0071a530(param_1);
        if (iVar4 == 0) {
          *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
          FID_conflict____longjmp_internal((int *)(param_1 + 0xc),3);
        }
        *(byte **)(iVar4 + 0xc) = pbVar6;
        pcVar7[-(uint)(*pcVar7 != '\0')] = '\0';
      }
      return pcVar7;
    }
    if (cVar2 == '\0') {
      if ((char)param_4 == '-') {
        *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),7);
      }
      if ((char)param_4 == '[') {
        *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),8);
      }
    }
    *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
    FID_conflict____longjmp_internal((int *)(param_1 + 0xc),5);
  }
  pcVar7 = (char *)(in_EAX + 2);
  if (((((*pcVar7 == 'C') && (pcVar7 = (char *)(in_EAX + 3), *pcVar7 == 'D')) &&
       (pcVar7 = (char *)(in_EAX + 4), *pcVar7 == 'A')) &&
      ((pcVar7 = (char *)(in_EAX + 5), *pcVar7 == 'T' &&
       (pcVar7 = (char *)(in_EAX + 6), *pcVar7 == 'A')))) &&
     (pcVar7 = (char *)(in_EAX + 7), *pcVar7 == '[')) {
    pcVar7 = (char *)(in_EAX + 8);
    if ((param_3 & 4) == 0) {
      cVar2 = *pcVar7;
      do {
        if (cVar2 == '\0') {
LAB_0071b001:
          *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
          FID_conflict____longjmp_internal((int *)(param_1 + 0xc),8);
        }
        if (((cVar2 == ']') && (pcVar7[1] == ']')) &&
           ((pcVar7[2] == '>' || ((pcVar7[2] == '\0' && ((char)param_4 == '>')))))) {
          if (*pcVar7 != '\0') goto LAB_0071afb9;
          goto LAB_0071b001;
        }
        cVar2 = pcVar7[1];
        pcVar7 = pcVar7 + 1;
      } while( true );
    }
    iVar4 = FUN_0071a530(param_1);
    if (iVar4 == 0) {
      *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
      FID_conflict____longjmp_internal((int *)(param_1 + 0xc),3);
    }
    *(char **)(iVar4 + 0xc) = pcVar7;
    if ((param_3 & 0x20) != 0) {
      pcVar7 = (char *)FUN_0071ab60(param_4);
      if (pcVar7 == (char *)0x0) {
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar4 + 0xc);
                    /* WARNING: Subroutine does not return */
        FID_conflict____longjmp_internal((int *)(param_1 + 0xc),8);
      }
LAB_0071afba:
      return pcVar7 + (pcVar7[1] == '>') + 1;
    }
    if (*pcVar7 != '\0') {
      do {
        if (((*pcVar7 == ']') && (pcVar7[1] == ']')) &&
           ((pcVar7[2] == '>' || ((pcVar7[2] == '\0' && ((char)param_4 == '>')))))) break;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar7 != '\0');
      if (*pcVar7 != '\0') {
        *pcVar7 = '\0';
LAB_0071afb9:
        pcVar7 = pcVar7 + 1;
        goto LAB_0071afba;
      }
    }
  }
  *(char **)(param_1 + 8) = pcVar7;
                    /* WARNING: Subroutine does not return */
  FID_conflict____longjmp_internal((int *)(param_1 + 0xc),8);
}

