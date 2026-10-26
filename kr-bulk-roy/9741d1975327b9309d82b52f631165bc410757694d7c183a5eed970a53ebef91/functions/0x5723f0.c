
void FUN_005723f0(void)

{
  char cVar1;
  int *piVar2;
  
  FUN_00572100();
  FUN_00572110();
  cVar1 = FUN_00572220();
  while (cVar1 != '\0') {
    piVar2 = (int *)thunk_FUN_00572200();
    if (*piVar2 != 0) {
      FUN_005724e0();
    }
    FUN_005721f0();
    FUN_00572110();
    cVar1 = FUN_00572220();
  }
  FUN_00572500();
  return;
}

