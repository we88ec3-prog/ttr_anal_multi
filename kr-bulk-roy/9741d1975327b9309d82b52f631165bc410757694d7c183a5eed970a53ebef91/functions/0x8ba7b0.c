
void FUN_008ba7b0(void)

{
  undefined4 uVar1;
  int *unaff_ESI;
  
  uVar1 = *(undefined4 *)(*unaff_ESI + 100);
  if (*(code **)(unaff_ESI[3] + 8) != (code *)0x0) {
    (**(code **)(unaff_ESI[3] + 8))();
  }
  FUN_008b9f80(uVar1);
  return;
}

