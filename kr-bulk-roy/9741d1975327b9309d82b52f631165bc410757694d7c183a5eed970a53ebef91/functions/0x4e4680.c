
undefined4 FUN_004e4680(int param_1,uint param_2)

{
  char *pcVar1;
  int in_ECX;
  uint uVar2;
  
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 2) / 3;
  }
  if (uVar2 != 0) {
    pcVar1 = (char *)(param_1 + 2);
    do {
      if (*pcVar1 == '\x01') {
        *(undefined2 *)(in_ECX + 0x698d) = *(undefined2 *)(pcVar1 + 1);
      }
      pcVar1 = pcVar1 + 3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}

