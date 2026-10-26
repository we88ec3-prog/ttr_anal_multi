
void FUN_008d9480(char *param_1)

{
  int *in_EAX;
  char cVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint local_c;
  int local_8;
  
  local_8 = in_EAX[2];
  local_c = (in_ECX - (int)param_1) * 8;
  uVar2 = 0;
  puVar5 = (undefined1 *)*in_EAX;
  uVar4 = 0x80;
  cVar1 = '\0';
  if (in_EAX[4] < (int)local_c) {
    local_c = in_EAX[4];
  }
  uVar3 = local_c & 7;
  if (0 < (int)local_c) {
    do {
      if ((local_c & 7) == uVar3) {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
      }
      if (cVar1 < '\0') {
        uVar2 = uVar2 | uVar4;
      }
      cVar1 = cVar1 * '\x02';
      local_8 = local_8 + -1;
      uVar4 = uVar4 >> 1;
      if (local_8 < 1) {
        *puVar5 = (char)uVar2;
        local_8 = in_EAX[2];
        *in_EAX = *in_EAX + in_EAX[1];
        puVar5 = (undefined1 *)*in_EAX;
LAB_008d950d:
        uVar2 = 0;
        uVar4 = 0x80;
      }
      else if (uVar4 == 0) {
        *puVar5 = (char)uVar2;
        puVar5 = puVar5 + 1;
        goto LAB_008d950d;
      }
      local_c = local_c - 1;
    } while (0 < (int)local_c);
    if (uVar4 != 0x80) {
      *puVar5 = (char)uVar2;
    }
  }
  return;
}

