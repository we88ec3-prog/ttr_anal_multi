
void FUN_007e8e90(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined1 local_c [8];
  
  if (*(int *)(unaff_EDI + 8) == 0) {
LAB_007e8ea7:
    FUN_007e9140(unaff_ESI,1,param_2);
    return;
  }
  if (param_1 == (int *)**(int **)(unaff_EDI + 4)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
      FUN_007e9140(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == *(int **)(unaff_EDI + 4)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
      FUN_007e9140(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
      FUN_007d4bc0();
      cVar1 = FUN_0049ae30();
      if (cVar1 != '\0') {
        if (*(char *)(param_1[2] + 0x59) == '\0') {
          FUN_007e9140(unaff_ESI,1,param_2);
          return;
        }
        FUN_007e9140(unaff_ESI,0,param_2);
        return;
      }
    }
    cVar1 = FUN_0049ae30();
    if ((cVar1 != '\0') &&
       ((FUN_007aa730(), param_1 == *(int **)(unaff_EDI + 4) ||
        (cVar1 = FUN_0049ae30(), cVar1 != '\0')))) {
      if (*(char *)(param_1[2] + 0x59) != '\0') {
        FUN_007e9140(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_007e8ea7;
    }
  }
  puVar2 = (undefined4 *)FUN_007e9000(unaff_EDI,local_c,param_2);
  *unaff_ESI = *puVar2;
  return;
}

