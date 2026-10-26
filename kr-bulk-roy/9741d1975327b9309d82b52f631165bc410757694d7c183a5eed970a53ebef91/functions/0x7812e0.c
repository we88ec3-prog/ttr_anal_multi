
uint FUN_007812e0(uint param_1)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  
  uVar1 = **(uint **)(in_ECX + 0x20);
  if ((uVar1 != 0) && (**(uint **)(in_ECX + 0x10) < uVar1)) {
    cVar2 = (char)param_1;
    if ((param_1 == 0xffffffff) ||
       ((cVar2 == *(char *)(uVar1 - 1) || ((*(byte *)(in_ECX + 0x48) & 2) == 0)))) {
      **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) + 1;
      **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + -1;
      if (param_1 != 0xffffffff) {
        if (*(char *)**(undefined4 **)(in_ECX + 0x20) != cVar2) {
          *(char *)**(undefined4 **)(in_ECX + 0x20) = cVar2;
        }
        return param_1 & 0xff;
      }
      return 0;
    }
  }
  return 0xffffffff;
}

