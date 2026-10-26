
char * FUN_0071f780(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *in_EAX;
  char *pcVar4;
  
  switch(*(undefined1 *)*param_2) {
  case 0x62:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
    pcVar4 = (char *)FUN_0071f6b0();
    if (pcVar4 != (char *)0x0) {
      iVar1 = *in_EAX;
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      pcVar4[0] = '-';
      pcVar4[1] = '\x04';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      *(int *)(pcVar4 + 4) = iVar1;
      return pcVar4;
    }
    break;
  case 99:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 1)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (param_3 != 2)) {
        cVar3 = FUN_0071d0a0();
        if ((cVar3 == '\0') || (param_3 < 2)) {
          cVar3 = FUN_0071d0a0();
          if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
          pcVar4 = (char *)FUN_0071f6b0();
          if (pcVar4 != (char *)0x0) {
            iVar1 = *in_EAX;
            pcVar4[8] = '\0';
            pcVar4[9] = '\0';
            pcVar4[10] = '\0';
            pcVar4[0xb] = '\0';
            pcVar4[0xc] = '\0';
            pcVar4[0xd] = '\0';
            pcVar4[0xe] = '\0';
            pcVar4[0xf] = '\0';
            pcVar4[0] = '6';
            pcVar4[1] = '\x02';
            pcVar4[2] = '\0';
            pcVar4[3] = '\0';
            *(int *)(pcVar4 + 4) = iVar1;
            return pcVar4;
          }
        }
        else {
          pcVar4 = (char *)FUN_0071f6b0();
          if (pcVar4 != (char *)0x0) {
            iVar1 = *in_EAX;
            iVar2 = in_EAX[1];
            pcVar4[0xc] = '\0';
            pcVar4[0xd] = '\0';
            pcVar4[0xe] = '\0';
            pcVar4[0xf] = '\0';
            pcVar4[0] = '!';
            pcVar4[1] = '\x03';
            pcVar4[2] = '\0';
            pcVar4[3] = '\0';
            *(int *)(pcVar4 + 4) = iVar1;
            *(int *)(pcVar4 + 8) = iVar2;
            return pcVar4;
          }
        }
      }
      else {
        pcVar4 = (char *)FUN_0071f6b0();
        if (pcVar4 != (char *)0x0) {
          iVar1 = *in_EAX;
          iVar2 = in_EAX[1];
          pcVar4[0xc] = '\0';
          pcVar4[0xd] = '\0';
          pcVar4[0xe] = '\0';
          pcVar4[0xf] = '\0';
          pcVar4[0] = '#';
          pcVar4[1] = '\x03';
          pcVar4[2] = '\0';
          pcVar4[3] = '\0';
          *(int *)(pcVar4 + 4) = iVar1;
          *(int *)(pcVar4 + 8) = iVar2;
          return pcVar4;
        }
      }
    }
    else {
      if (*(char *)(*in_EAX + 1) != '\x01') {
                    /* WARNING: Subroutine does not return */
        FUN_0071f620();
      }
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        iVar1 = *in_EAX;
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[0] = '\x17';
        pcVar4[1] = '\x02';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        return pcVar4;
      }
    }
    break;
  default:
switchD_0071f7a6_caseD_64:
                    /* WARNING: Subroutine does not return */
    FUN_0071f620();
  case 0x66:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 0)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        iVar1 = *in_EAX;
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[0] = '5';
        pcVar4[1] = '\x02';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        return pcVar4;
      }
    }
    else {
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        pcVar4[4] = '\0';
        pcVar4[5] = '\0';
        pcVar4[6] = '\0';
        pcVar4[7] = '\0';
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[0] = '0';
        pcVar4[1] = '\x04';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        return pcVar4;
      }
    }
    break;
  case 0x69:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
    pcVar4 = (char *)FUN_0071f6b0();
    if (pcVar4 != (char *)0x0) {
      iVar1 = *in_EAX;
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      pcVar4[0] = '\x18';
      pcVar4[1] = '\x01';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      *(int *)(pcVar4 + 4) = iVar1;
      return pcVar4;
    }
    break;
  case 0x6c:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 0)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (param_3 != 1)) {
        cVar3 = FUN_0071d0a0();
        if ((cVar3 != '\0') && (param_3 < 2)) {
          pcVar4 = (char *)FUN_0071f720(0x19,0x1a,in_EAX);
          return pcVar4;
        }
        goto switchD_0071f7a6_caseD_64;
      }
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        iVar1 = *in_EAX;
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[0] = '1';
        pcVar4[1] = '\x04';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        return pcVar4;
      }
    }
    else {
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        pcVar4[4] = '\0';
        pcVar4[5] = '\0';
        pcVar4[6] = '\0';
        pcVar4[7] = '\0';
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[0] = '\x15';
        pcVar4[1] = '\x02';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        return pcVar4;
      }
    }
    break;
  case 0x6e:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 != '\0') && (param_3 < 2)) {
      pcVar4 = (char *)FUN_0071f720(0x1d,0x1e,in_EAX);
      return pcVar4;
    }
    cVar3 = FUN_0071d0a0();
    if ((cVar3 != '\0') && (param_3 < 2)) {
      pcVar4 = (char *)FUN_0071f720(0x1b,0x1c,in_EAX);
      return pcVar4;
    }
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (1 < param_3)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (param_3 != 1)) {
        cVar3 = FUN_0071d0a0();
        if ((cVar3 == '\0') || (1 < param_3)) goto switchD_0071f7a6_caseD_64;
        pcVar4 = (char *)FUN_0071f6b0();
        if (pcVar4 != (char *)0x0) {
          iVar1 = *in_EAX;
          pcVar4[3] = '\0';
          pcVar4[8] = '\0';
          pcVar4[9] = '\0';
          pcVar4[10] = '\0';
          pcVar4[0xb] = '\0';
          pcVar4[0xc] = '\0';
          pcVar4[0xd] = '\0';
          pcVar4[0xe] = '\0';
          pcVar4[0xf] = '\0';
          *pcVar4 = (param_3 != 0) + '2';
          pcVar4[1] = '\x02';
          pcVar4[2] = '\0';
          *(int *)(pcVar4 + 4) = iVar1;
          return pcVar4;
        }
      }
      else {
        pcVar4 = (char *)FUN_0071f6b0();
        if (pcVar4 != (char *)0x0) {
          iVar1 = *in_EAX;
          pcVar4[8] = '\0';
          pcVar4[9] = '\0';
          pcVar4[10] = '\0';
          pcVar4[0xb] = '\0';
          pcVar4[0xc] = '\0';
          pcVar4[0xd] = '\0';
          pcVar4[0xe] = '\0';
          pcVar4[0xf] = '\0';
          pcVar4[0] = '.';
          pcVar4[1] = '\x04';
          pcVar4[2] = '\0';
          pcVar4[3] = '\0';
          *(int *)(pcVar4 + 4) = iVar1;
          return pcVar4;
        }
      }
    }
    else {
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        iVar1 = *in_EAX;
        *pcVar4 = (param_3 != 0) + '*';
        iVar2 = in_EAX[1];
        pcVar4[3] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        pcVar4[1] = '\x03';
        pcVar4[2] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        *(int *)(pcVar4 + 8) = iVar2;
        return pcVar4;
      }
    }
    break;
  case 0x70:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 0)) goto switchD_0071f7a6_caseD_64;
    pcVar4 = (char *)FUN_0071f6b0();
    if (pcVar4 != (char *)0x0) {
      pcVar4[4] = '\0';
      pcVar4[5] = '\0';
      pcVar4[6] = '\0';
      pcVar4[7] = '\0';
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      pcVar4[0] = '\x16';
      pcVar4[1] = '\x02';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      return pcVar4;
    }
    break;
  case 0x72:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
    pcVar4 = (char *)FUN_0071f6b0();
    if (pcVar4 != (char *)0x0) {
      iVar1 = *in_EAX;
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      pcVar4[0] = '7';
      pcVar4[1] = '\x02';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      *(int *)(pcVar4 + 4) = iVar1;
      return pcVar4;
    }
    break;
  case 0x73:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (1 < param_3)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (1 < param_3)) {
        cVar3 = FUN_0071d0a0();
        if ((cVar3 == '\0') || (param_3 != 2)) {
          cVar3 = FUN_0071d0a0();
          if ((cVar3 == '\0') || (param_3 != 2)) {
            cVar3 = FUN_0071d0a0();
            if ((cVar3 == '\0') || (param_3 != 2)) {
              cVar3 = FUN_0071d0a0();
              if ((cVar3 == '\0') || ((param_3 != 2 && (param_3 != 3)))) {
                cVar3 = FUN_0071d0a0();
                if ((cVar3 == '\0') || (param_3 != 1)) goto switchD_0071f7a6_caseD_64;
                if (*(char *)(*in_EAX + 1) != '\x01') {
                    /* WARNING: Subroutine does not return */
                  FUN_0071f620();
                }
                pcVar4 = (char *)FUN_0071f6b0();
                if (pcVar4 != (char *)0x0) {
                  iVar1 = *in_EAX;
                  pcVar4[0] = '4';
                  pcVar4[1] = '\x02';
                  pcVar4[2] = '\0';
                  pcVar4[3] = '\0';
                  *(int *)(pcVar4 + 4) = iVar1;
                  pcVar4[8] = '\0';
                  pcVar4[9] = '\0';
                  pcVar4[10] = '\0';
                  pcVar4[0xb] = '\0';
                  pcVar4[0xc] = '\0';
                  pcVar4[0xd] = '\0';
                  pcVar4[0xe] = '\0';
                  pcVar4[0xf] = '\0';
                  return pcVar4;
                }
              }
              else {
                pcVar4 = (char *)FUN_0071f6b0();
                if (pcVar4 != (char *)0x0) {
                  iVar1 = *in_EAX;
                  *pcVar4 = (param_3 != 2) + '&';
                  iVar2 = in_EAX[1];
                  pcVar4[3] = '\0';
                  pcVar4[1] = '\x03';
                  pcVar4[2] = '\0';
                  *(int *)(pcVar4 + 4) = iVar1;
                  *(int *)(pcVar4 + 8) = iVar2;
                  pcVar4[0xc] = '\0';
                  pcVar4[0xd] = '\0';
                  pcVar4[0xe] = '\0';
                  pcVar4[0xf] = '\0';
                  return pcVar4;
                }
              }
            }
            else {
              pcVar4 = (char *)FUN_0071f6b0();
              if (pcVar4 != (char *)0x0) {
                iVar1 = *in_EAX;
                iVar2 = in_EAX[1];
                pcVar4[0] = '%';
                pcVar4[1] = '\x03';
                pcVar4[2] = '\0';
                pcVar4[3] = '\0';
                *(int *)(pcVar4 + 4) = iVar1;
                *(int *)(pcVar4 + 8) = iVar2;
                pcVar4[0xc] = '\0';
                pcVar4[0xd] = '\0';
                pcVar4[0xe] = '\0';
                pcVar4[0xf] = '\0';
                return pcVar4;
              }
            }
          }
          else {
            pcVar4 = (char *)FUN_0071f6b0();
            if (pcVar4 != (char *)0x0) {
              iVar1 = *in_EAX;
              iVar2 = in_EAX[1];
              pcVar4[0] = '$';
              pcVar4[1] = '\x03';
              pcVar4[2] = '\0';
              pcVar4[3] = '\0';
              *(int *)(pcVar4 + 4) = iVar1;
              *(int *)(pcVar4 + 8) = iVar2;
              pcVar4[0xc] = '\0';
              pcVar4[0xd] = '\0';
              pcVar4[0xe] = '\0';
              pcVar4[0xf] = '\0';
              return pcVar4;
            }
          }
        }
        else {
          pcVar4 = (char *)FUN_0071f6b0();
          if (pcVar4 != (char *)0x0) {
            iVar1 = *in_EAX;
            iVar2 = in_EAX[1];
            pcVar4[0] = '\"';
            pcVar4[1] = '\x04';
            pcVar4[2] = '\0';
            pcVar4[3] = '\0';
            *(int *)(pcVar4 + 4) = iVar1;
            *(int *)(pcVar4 + 8) = iVar2;
            pcVar4[0xc] = '\0';
            pcVar4[0xd] = '\0';
            pcVar4[0xe] = '\0';
            pcVar4[0xf] = '\0';
            return pcVar4;
          }
        }
      }
      else {
        pcVar4 = (char *)FUN_0071f6b0();
        if (pcVar4 != (char *)0x0) {
          cVar3 = (param_3 != 0) + '(';
          goto LAB_0071fc92;
        }
      }
    }
    else {
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        cVar3 = (param_3 != 0) + '\x1f';
LAB_0071fc92:
        iVar1 = *in_EAX;
        *pcVar4 = cVar3;
        pcVar4[1] = '\x03';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        return pcVar4;
      }
    }
    break;
  case 0x74:
    cVar3 = FUN_0071d0a0();
    if ((cVar3 == '\0') || (param_3 != 3)) {
      cVar3 = FUN_0071d0a0();
      if ((cVar3 == '\0') || (param_3 != 0)) goto switchD_0071f7a6_caseD_64;
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        pcVar4[4] = '\0';
        pcVar4[5] = '\0';
        pcVar4[6] = '\0';
        pcVar4[7] = '\0';
        pcVar4[0] = '/';
        pcVar4[1] = '\x04';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        pcVar4[8] = '\0';
        pcVar4[9] = '\0';
        pcVar4[10] = '\0';
        pcVar4[0xb] = '\0';
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        return pcVar4;
      }
    }
    else {
      pcVar4 = (char *)FUN_0071f6b0();
      if (pcVar4 != (char *)0x0) {
        iVar1 = *in_EAX;
        iVar2 = in_EAX[1];
        pcVar4[0] = ',';
        pcVar4[1] = '\x03';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        *(int *)(pcVar4 + 4) = iVar1;
        *(int *)(pcVar4 + 8) = iVar2;
        pcVar4[0xc] = '\0';
        pcVar4[0xd] = '\0';
        pcVar4[0xe] = '\0';
        pcVar4[0xf] = '\0';
        return pcVar4;
      }
    }
  }
  return (char *)0x0;
}

