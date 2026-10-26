
char FUN_008c3720(int param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_2;
  do {
    uVar2 = uVar3 + 1;
    if (0xff < uVar2) {
      *param_2 = 0;
      return '\0';
    }
    cVar1 = *(char *)(uVar3 + 7 + *(int *)(param_1 + 0x10));
    uVar3 = uVar2;
  } while (cVar1 == '\0');
  *param_2 = uVar2;
  return cVar1;
}

