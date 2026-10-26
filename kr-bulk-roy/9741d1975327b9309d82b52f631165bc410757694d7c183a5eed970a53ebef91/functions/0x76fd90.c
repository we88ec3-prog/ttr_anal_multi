
void FUN_0076fd90(undefined4 param_1,int param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (-(uint)(param_3 != '\0') & 300) + 400;
  *(undefined4 *)(in_ECX + 0xc) = param_4;
  iVar1 = D3DXCreateFontW(param_4,-param_2,0,iVar2,1,0,1,0,4,0,param_1,in_ECX + 4);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  iVar1 = D3DXCreateFontW(param_4,-param_2,0,iVar2,1,0,1,0,4,0,param_1,(undefined4 *)(in_ECX + 8));
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}

