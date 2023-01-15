! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
! Fun with Fortran
! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
      program fun_with_sums
      implicit none ! default is names begining i, j, k, l, m, n are integer types

      double precision :: h
      real(8), dimension(3) :: t
      character(len=6), dimension(2) :: lbl = (/ 'arccos', 'arctan' /)
      double precision, dimension(2) :: pi
      logical(1) :: fmats = .true.
      integer :: ix, p_
      integer :: trigr
      real(8) :: myhypot !! function
      type mypi
        character(len=6) :: method
        double precision :: pi
      end type
      type(mypi), dimension(2) :: mypies = [ mypi( 'arccos', 0.0 ), mypi( 'arctan', 0.0 ) ]
      ! mypies = [ mypi( 'arccos', 0.0 ), mypi( 'arctan', 0.0 ) ]

      print *, "Calculate hypotenuse of a 3,4,5 triangle [Pythagorean theorem]:"
      write (6, '(1h ,a)') '(Using ''myhypot'' local function)'
     ! calculate hypotenuse of 3,4,5 triangle (result should be 5);
      t = [ 3.0, 4.0, 5.0 ]
      h = myhypot(t(1), t(2))

      trigr = 1
      goto (10, 20, 30), trigr ! computed goto: similar to switch(trigr)
                ! default:

10    continue  ! case 1:
      write (unit=6, fmt='(1H ,4(F21.16, 5X))') t(1 : 3), h
      go to 40  ! break

20    continue  ! case 2:
      print '(1H ,4(F21.16, 5X))', t(1 : 3), h
      go to 40  ! break

30    continue  ! case 3:
      print *, t(1 : 3), h

40    continue  ! end switch

      ! @see: https://www.ibm.com/docs/en/zos/2.1.0?topic=scctrcild-using-carriage-control-characters-in-line-data-records
      ! same thing using select case (...)
      write (unit=6, fmt='(/1H )')
1010  format (1H+,A63)
1100  format (1H ,4(F21.16,5X))
                      !....+....1....+....2....+....3....+....4....+....5....+....6...
      write (6, 1010) "Calculate hypotenuse of a 3,4,5 triangle [Pythagorean theorem]:"
      write (6, '(1h ,a)') '(Using ''hypot'' intrinsic function)'
      h = hypot(t(1), t(2)) !! intrinsic function
      trigr = 10
      select case (trigr)
        case (1)
          write (unit=6, fmt='(1H ,4(F21.16, 5X))') t(1 : 3), h

        case (2)
          print '(1H ,4(F21.16, 5X))', t(1 : 3), h

        case (3)
          print *, t(1 : 3), h

        case default
          write (unit=6, fmt=1100) t(1 : 3), h

      end select

10000 format (1H ,'π [', A6, ']:', F21.16)
      call pie(pi)
      do ix = 1, 2
        if (fmats) then
          write (6, 10000) lbl(ix), pi(ix)
        else
          write (unit=6, fmt="('π [', A6, ']:', F21.16)") lbl(ix), pi(ix)
        end if
      end do

      ! - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      print '(/, 1H+,A)', 'With a user defined ''type'':'
      mypies(1)%pi = pi(1)
      mypies(2)%pi = pi(2)

      do p_ = 1, size(mypies)
        write (unit=6, fmt="(1H ,'π [', A6, ']:', F21.16)") mypies(p_)%method, mypies(p_)%pi
      end do

      stop
      end program fun_with_sums

! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
! Calculate hypotenuse of a triangle [Pythagorean theorem] h = √(a**2 + b**2):"
! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
      real(8) function myhypot(a, b) result(h)
      implicit none
      real(8), intent(in) :: a, b

      h = (a ** 2 + b ** 2) ** 0.5

      return
      end function myhypot

! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
! Calculate π with arccos & arctan.
! - - - - + - - - - | - - - - + - - - - | - - - - + - - - - | - - - - + - - - - |
      subroutine pie(pies)
      implicit none
      double precision, dimension(2), intent(out) :: pies

      write (unit=6, fmt='(1H /1H ,A13)') 'Calculate π:'
      pies(1) = 2.0 * acos(0.0)
      pies(2) = 4.0 * atan(1.0)

      return
      end subroutine pie
