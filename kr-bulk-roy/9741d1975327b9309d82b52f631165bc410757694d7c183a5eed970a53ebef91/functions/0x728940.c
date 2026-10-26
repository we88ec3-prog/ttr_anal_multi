
undefined4 FUN_00728940(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0x1c) != 0)) &&
     (*(code **)(unaff_ESI + 0x24) != (code *)0x0)) {
    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x34);
    if (iVar1 != 0) {
      (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),iVar1);
    }
    (**(code **)(unaff_ESI + 0x24))
              (*(undefined4 *)(unaff_ESI + 0x28),*(undefined4 *)(unaff_ESI + 0x1c));
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}

