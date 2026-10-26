
void FUN_00765ef0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x114);
  iVar2 = *(int *)(param_1 + 0x110);
  iVar3 = param_2;
  do {
    if (iVar1 - iVar2 >> 2 <= iVar3) {
LAB_00765f4b:
      FUN_00766390(param_2,0,0);
      return;
    }
    iVar4 = (in_EDX - *(int *)(*(int *)(*(int *)(param_1 + 0x110) + iVar3 * 4) + 0x10)) + in_ECX;
    if (iVar4 < 1) {
      FUN_00757e40(in_EDX,in_ECX);
      goto LAB_00765f4b;
    }
    FUN_00757e40(in_EDX,in_ECX);
    iVar3 = iVar3 + 1;
    in_ECX = 0;
    in_EDX = iVar4;
  } while( true );
}

