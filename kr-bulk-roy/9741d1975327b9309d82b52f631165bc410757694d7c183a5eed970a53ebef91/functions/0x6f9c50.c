
undefined4 * FUN_006f9c50(void)

{
  int iVar1;
  double *in_EAX;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(in_EAX + 1);
  if (iVar1 != 0) {
    if (iVar1 == 3) {
      if (*in_EAX == (double)(int)ROUND(*in_EAX)) {
        puVar2 = (undefined4 *)FUN_006f9b70((int)ROUND(*in_EAX));
        return puVar2;
      }
    }
    else if (iVar1 == 4) {
      puVar2 = (undefined4 *)FUN_006f9c10();
      return puVar2;
    }
    puVar2 = (undefined4 *)FUN_006f9100();
    if (puVar2 != (undefined4 *)0x0) {
      do {
        if (puVar2[6] == *(int *)(in_EAX + 1)) {
          switch(puVar2[6]) {
          case 0:
            return puVar2;
          default:
            if (puVar2[4] == *(int *)in_EAX) {
              return puVar2;
            }
            break;
          case 3:
            if (*in_EAX == *(double *)(puVar2 + 4)) {
              return puVar2;
            }
          }
        }
        puVar2 = (undefined4 *)puVar2[7];
      } while (puVar2 != (undefined4 *)0x0);
    }
  }
  return &DAT_00c0bfc8;
}

