package GildedRose;

use strict;
use warnings;

sub new {
    my ( $class, %attrs ) = @_;
    return bless \%attrs, $class;
}

sub update_quality_of_item {
  my $item = shift;
        if (   $item->{name} ne 'Aged Brie'
            && $item->{name} ne 'Backstage passes to a TAFKAL80ETC concert' )
        {
            if ( $item->{quality} > 0 ) {
                if ( $item->{name} ne 'Sulfuras, Hand of Ragnaros' ) {
                    $item->{quality} = $item->{quality} - 1;
                }
            }
        }
        else {
            if ( $item->{quality} < 50 ) {
                $item->{quality} = $item->{quality} + 1;

                if ( $item->{name} eq
                    'Backstage passes to a TAFKAL80ETC concert' )
                {
                    if ( $item->{sell_in} < 11 ) {
                        if ( $item->{quality} < 50 ) {
                            $item->{quality} = $item->{quality} + 1;
                        }
                    }

                    if ( $item->{sell_in} < 6 ) {
                        if ( $item->{quality} < 50 ) {
                            $item->{quality} = $item->{quality} + 1;
                        }
                    }
                }
            }
        }

        if ( $item->{name} ne 'Sulfuras, Hand of Ragnaros' ) {
            $item->{sell_in} = $item->{sell_in} - 1;
        }

        if ( $item->{sell_in} < 0 ) {
            if ( $item->{name} ne 'Aged Brie' ) {
                if ( $item->{name} ne
                    'Backstage passes to a TAFKAL80ETC concert' )
                {
                    if ( $item->{quality} > 0 ) {
                        if ( $item->{name} ne 'Sulfuras, Hand of Ragnaros' ) {
                            $item->{quality} = $item->{quality} - 1;
                        }
                    }
                }
                else {
                    $item->{quality} = $item->{quality} - $item->{quality};
                }
            }
            else {
                if ( $item->{quality} < 50 ) {
                    $item->{quality} = $item->{quality} + 1;
                }
            }
        }
    return;
}

sub update_quality_dexterity_vest {
  update_quality_of_item(shift);
}

sub update_quality_aged_brie {
  update_quality_of_item(shift);
}

sub update_quality_elixir_of_the_mongoose {
  update_quality_of_item(shift);
}

sub update_quality_sulfuras {
  update_quality_of_item(shift);
}

sub update_quality_backstage_passes {
  update_quality_of_item(shift);
}

sub update_quality_conjured_mana_cake {
  update_quality_of_item(shift);
}

sub update_quality {
    my $self = shift;
    for my $item ( @{ $self->{items} } ) {
      if ($item->{name} eq "+5 Dexterity Vest") {
        update_quality_dexterity_vest($item);
      } elsif ($item->{name} eq "Aged Brie") {
        update_quality_aged_brie($item);
      } elsif ($item->{name} eq "Elixir of the Mongoose") {
        update_quality_elixir_of_the_mongoose($item);
      } elsif ($item->{name} eq "Sulfuras, Hand of Ragnaros") {
        update_quality_sulfuras($item);
      } elsif ($item->{name} eq "Backstage passes to a TAFKAL80ETC concert") {
        update_quality_backstage_passes($item);
      } elsif ($item->{name} eq "Conjured Mana Cake") {
        update_quality_conjured_mana_cake($item);
      }
    }
}

1;
