
void FUN_007d0420(int *param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined1 local_c [8];
  
  if (*(int *)(in_EAX + 8) == 0) {
LAB_007d043a:
    FUN_00574ce0(unaff_ESI,1,param_2);
    return;
  }
  if (param_1 == (int *)**(int **)(in_EAX + 4)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
LAB_007d0464:
      FUN_00574ce0(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == *(int **)(in_EAX + 4)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
      FUN_00574ce0(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    cVar1 = FUN_0049ae30();
    if (cVar1 != '\0') {
      FUN_00574e80();
      cVar1 = FUN_0049ae30();
      if (cVar1 != '\0') {
        if (*(char *)(param_1[2] + 0x2d) != '\0') {
          FUN_00574ce0(unaff_ESI,0,param_2);
          return;
        }
        goto LAB_007d0464;
      }
    }
    cVar1 = FUN_0049ae30();
    if ((cVar1 != '\0') &&
       ((FUN_00717a50(), param_1 == *(int **)(in_EAX + 4) || (cVar1 = FUN_0049ae30(), cVar1 != '\0')
        ))) {
      if (*(char *)(param_1[2] + 0x2d) != '\0') {
        FUN_00574ce0(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_007d043a;
    }
  }
  puVar2 = (undefined4 *)FUN_007e2910(in_EAX,local_c,param_2);
  *unaff_ESI = *puVar2;
  return;
}

