
void FUN_00709060(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  FUN_006f6060();
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = puVar1[-4];
  puVar1[1] = puVar1[-3];
  puVar1[2] = puVar1[-2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  FUN_006f6590(0,&PTR_s_close_00c0bb20);
  return;
}

