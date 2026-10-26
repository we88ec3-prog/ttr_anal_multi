
void FUN_00478cc0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  FUN_007545b0();
  iVar1 = in_ECX[0x5a];
  iVar2 = *(int *)(in_ECX[0x58] + 0x14) + 0xf;
  (**(code **)(*(int *)in_ECX[0x5a] + 0xbc))
            (*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
             iVar2 + *(int *)(iVar1 + 0xc));
  (**(code **)(*in_ECX + 0xbc))(in_ECX[2],in_ECX[3],in_ECX[4],iVar2 + in_ECX[3]);
  return;
}

