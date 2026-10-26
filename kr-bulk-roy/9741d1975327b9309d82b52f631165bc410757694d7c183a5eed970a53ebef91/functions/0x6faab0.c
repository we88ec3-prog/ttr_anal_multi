
void FUN_006faab0(void)

{
  int *piVar1;
  int in_EAX;
  int in_ECX;
  
  switch(*(undefined1 *)(in_EAX + 4)) {
  case 4:
    piVar1 = (int *)(*(int *)(in_ECX + 0x10) + 4);
    *piVar1 = *piVar1 + -1;
    FUN_00700880();
    return;
  case 5:
    FUN_006f9a10();
    return;
  case 6:
    FUN_006fd9e0();
    return;
  case 7:
    FUN_00700880();
    break;
  case 8:
    FUN_006f7460();
    return;
  case 9:
    FUN_006fd950();
    return;
  case 10:
    FUN_006fd830();
    return;
  }
  return;
}

