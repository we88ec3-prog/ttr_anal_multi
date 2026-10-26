
void FUN_004c9ff0(void)

{
  int *in_ECX;
  int *piVar1;
  int iVar2;
  
  *in_ECX = (int)CFSM<FSM,CActorState>::vftable;
  iVar2 = 0x19;
  piVar1 = in_ECX;
  do {
    piVar1 = piVar1 + 1;
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
      *piVar1 = 0;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  in_ECX[0x1a] = 0;
  return;
}

