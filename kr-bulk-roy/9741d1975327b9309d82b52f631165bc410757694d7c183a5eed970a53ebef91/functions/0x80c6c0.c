
void FUN_0080c6c0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
LAB_0080c6da:
    FUN_00574ce0(unaff_ESI,1,param_2);
    return;
  }
  if (param_1 == (int *)**(int **)(in_EAX + 4)) {
    cVar1 = FUN_005436a0();
    if (cVar1 != '\0') {
LAB_0080c704:
      FUN_00574ce0(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == *(int **)(in_EAX + 4)) {
    cVar1 = FUN_005436a0();
    if (cVar1 != '\0') {
      FUN_00574ce0(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    cVar1 = FUN_005436a0();
    if (cVar1 != '\0') {
      FUN_00574e80();
      cVar1 = FUN_005436a0();
      if (cVar1 != '\0') {
        if (*(char *)(param_1[2] + 0x2d) != '\0') {
          FUN_00574ce0(unaff_ESI,0,param_2);
          return;
        }
        goto LAB_0080c704;
      }
    }
    cVar1 = FUN_005436a0();
    if ((cVar1 != '\0') &&
       ((FUN_00717a50(), param_1 == *(int **)(in_EAX + 4) || (cVar1 = FUN_005436a0(), cVar1 != '\0')
        ))) {
      if (*(char *)(param_1[2] + 0x2d) != '\0') {
        FUN_00574ce0(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_0080c6da;
    }
  }
  puVar2 = (undefined4 *)FUN_0080c560(in_EAX,local_c,param_2);
  *unaff_ESI = *puVar2;
  return;
}

