
undefined4 FUN_0082d500(int param_1,uint param_2)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  uint in_EDX;
  uint unaff_EDI;
  
  do {
    if (param_2 <= in_EAX) {
      return 1;
    }
    if (unaff_EDI < in_EDX) {
      piVar1 = (int *)(*(int *)(param_1 + 0x20) + 8 +
                      (*(int *)(param_1 + 8) * in_EAX + unaff_EDI) * 0x18);
      uVar2 = unaff_EDI;
      do {
        if (((piVar1[2] == 0) || (*piVar1 != -1)) || (piVar1[-1] != 0)) {
          return 0;
        }
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 6;
      } while (uVar2 < in_EDX);
    }
    in_EAX = in_EAX + 1;
  } while( true );
}

