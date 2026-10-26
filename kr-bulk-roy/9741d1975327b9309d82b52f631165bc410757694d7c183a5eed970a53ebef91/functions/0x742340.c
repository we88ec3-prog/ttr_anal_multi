
void FUN_00742340(int *param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
LAB_0074235a:
    FUN_00742720(unaff_ESI,1,param_2);
    return;
  }
  if (param_1 == (int *)**(int **)(in_EAX + 4)) {
    cVar1 = FUN_007418b0();
    if (cVar1 != '\0') {
LAB_00742384:
      FUN_00742720(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == *(int **)(in_EAX + 4)) {
    cVar1 = FUN_007418b0();
    if (cVar1 != '\0') {
      FUN_00742720(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    cVar1 = FUN_007418b0();
    if (cVar1 != '\0') {
      FUN_00742a50();
      cVar1 = FUN_007418b0();
      if (cVar1 != '\0') {
        if (*(char *)(param_1[2] + 0x39) != '\0') {
          FUN_00742720(unaff_ESI,0,param_2);
          return;
        }
        goto LAB_00742384;
      }
    }
    cVar1 = FUN_007418b0();
    if ((cVar1 != '\0') &&
       ((FUN_0052d260(), param_1 == *(int **)(in_EAX + 4) || (cVar1 = FUN_007418b0(), cVar1 != '\0')
        ))) {
      if (*(char *)(param_1[2] + 0x39) != '\0') {
        FUN_00742720(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_0074235a;
    }
  }
  puVar2 = (undefined4 *)FUN_00742600(in_EAX,local_c,param_2);
  *unaff_ESI = *puVar2;
  return;
}

