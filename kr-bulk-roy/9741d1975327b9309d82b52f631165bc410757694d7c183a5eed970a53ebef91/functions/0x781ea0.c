
void FUN_00781ea0(void)

{
  undefined4 *in_EAX;
  int unaff_EDI;
  undefined4 *puVar1;
  undefined4 local_c [2];
  
  puVar1 = local_c;
  local_c[0] = 0;
  FUN_006ddcc0(*(undefined4 *)(unaff_EDI + 0x84),puVar1,4,0);
  if (puVar1 != (undefined4 *)0x0) {
    if ((undefined4 *)in_EAX[4] < puVar1) {
      FUN_00429630((int)puVar1 - (int)in_EAX[4],0);
    }
    else {
      FUN_00402c80(puVar1,0xffffffff);
    }
    if (0xf < (uint)in_EAX[5]) {
      in_EAX = (undefined4 *)*in_EAX;
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_006ddcc0(*(undefined4 *)(unaff_EDI + 0x84),in_EAX,puVar1,0);
    }
  }
  return;
}

