
void FUN_006ef4e0(undefined4 param_1,undefined1 *param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  byte *pbVar2;
  
  *param_2 = 0x25;
  pcVar1 = param_2 + 1;
  if ((param_4 & 0x20) != 0) {
    *pcVar1 = '+';
    pcVar1 = param_2 + 2;
  }
  if ((param_4 & 8) != 0) {
    *pcVar1 = '#';
    pcVar1 = pcVar1 + 1;
  }
  if (*param_3 == 'L') {
    pcVar1[0] = 'I';
    pcVar1[1] = '6';
    pcVar1[2] = '4';
    pbVar2 = (byte *)(pcVar1 + 3);
  }
  else {
    *pcVar1 = *param_3;
    pbVar2 = (byte *)(pcVar1 + 1);
  }
  if ((param_4 & 0xe00) == 0x400) {
    *pbVar2 = 0x6f;
    pbVar2[1] = 0;
    return;
  }
  if ((param_4 & 0xe00) != 0x800) {
    *pbVar2 = param_3[1];
    pbVar2[1] = 0;
    return;
  }
  *pbVar2 = ~((char)param_4 * '\b') & 0x20U | 0x58;
  pbVar2[1] = 0;
  return;
}

