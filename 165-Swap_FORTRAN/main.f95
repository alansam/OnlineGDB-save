
Program Hello
implicit none
! define integers
     integer :: i1, j1

     Print *, "Swapper - call-by-reference"


     i1 = 5
     j1 = 11
     print *, "I: ", i1, "J: ", j1
     call swap(i1, j1)
     print *, "I: ", i1, "J: ", j1

End Program Hello

subroutine swap(is, js)
     integer :: ks

     ks = is
     is = js
     js = ks
     return
end subroutine

